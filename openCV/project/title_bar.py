from PyQt5.QtWidgets import QWidget, QPushButton, QLabel, QHBoxLayout
from PyQt5.QtCore import Qt, QPoint

class MyTitleBar(QWidget):

    def __init__(self, parent):
        super(MyTitleBar, self).__init__()
        self.parent = parent
        self.initUI()

    def initUI(self):
        self.layout = QHBoxLayout()
        self.layout.setContentsMargins(0, 0, 0, 0)

        self.title = QLabel("My Own Bar")
        self.title.setFixedHeight(40)
        self.title.setAlignment(Qt.AlignVCenter | Qt.AlignLeft)
        self.title.setStyleSheet("""
            background-color: #1a1a1a;
            color: #ffffff;
            padding: 10px;
        """)

        btn_size = 35
        self.btn_close = self.createButton("x", self.btn_close_clicked, btn_size, "#c33d3d")
        self.btn_min = self.createButton("-", self.btn_min_clicked, btn_size, "#1a1a1a")

        self.layout.addWidget(self.title)
        self.layout.addWidget(self.btn_min)
        self.layout.addWidget(self.btn_close)

        self.setLayout(self.layout)

        self.start = QPoint(0, 0)
        self.pressing = False

    def createButton(self, text, clicked, size, bg_color):
        button = QPushButton(text)
        button.clicked.connect(clicked)
        button.setFixedSize(size, size)
        button.setStyleSheet(f"""
            background-color: {bg_color};
            color: #ffffff;
            font-size: 18px;
            border: none;
        """)
        button.setStyleSheet(f"""
            QPushButton {{
                background-color: {bg_color};
                color: #ffffff;
                font-size: 18px;
                border: none;
            }}
            QPushButton:hover {{
                background-color: {self.darkenColor(bg_color)};
            }}
        """)
        return button

    def darkenColor(self, color):
        r, g, b = self.hex_to_rgb(color)
        r = max(0, r - 10)
        g = max(0, g - 10)
        b = max(0, b - 10)
        return "#{:02x}{:02x}{:02x}".format(r, g, b)

    def hex_to_rgb(self, color):
        color = color.lstrip('#')
        return tuple(int(color[i:i+2], 16) for i in (0, 2, 4))

    def resizeEvent(self, QResizeEvent):
        super(MyTitleBar, self).resizeEvent(QResizeEvent)
        self.title.setFixedWidth(self.parent.width())

    def mousePressEvent(self, event):
        self.start = self.mapToGlobal(event.pos())
        self.pressing = True

    def mouseMoveEvent(self, event):
        if self.pressing:
            self.end = self.mapToGlobal(event.pos())
            self.movement = self.end - self.start
            self.parent.setGeometry(
                self.mapToGlobal(self.movement).x(),
                self.mapToGlobal(self.movement).y(),
                self.parent.width(),
                self.parent.height()
            )
            self.start = self.end

    def mouseReleaseEvent(self, QMouseEvent):
        self.pressing = False

    def btn_close_clicked(self):
        self.parent.close()

    def btn_min_clicked(self):
        self.parent.showMinimized()
