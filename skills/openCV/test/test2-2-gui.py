import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QVBoxLayout, QLabel
from PyQt5.QtGui import QIcon, QPainter, QColor, QFont
from PyQt5.QtCore import Qt, QPoint

class TitleBar(QWidget):
    def __init__(self, parent):
        super().__init__()
        self.parent = parent
        self.initUI()

    def initUI(self):
        # 타이틀 텍스트 라벨
        self.titleLabel = QLabel(self.parent.windowTitle(), self)
        self.titleLabel.setAlignment(Qt.AlignCenter)
        self.titleLabel.setStyleSheet("color: #f8f8f2;")

        # 닫기 버튼
        closeButton = QPushButton('X', self)
        closeButton.clicked.connect(self.parent.close)
        closeButton.setStyleSheet("""
            background-color: #ff5555;
            color: #f8f8f2;
            border-radius: 5px;
            padding: 5px;
        """)

        # 레이아웃 생성
        layout = QVBoxLayout()
        layout.addWidget(self.titleLabel)
        layout.addWidget(closeButton)
        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setBrush(QColor("#282a36"))
        painter.drawRect(self.rect())

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.dragPos = event.globalPos()
            event.accept()

    def mouseMoveEvent(self, event):
        if event.buttons() == Qt.LeftButton:
            self.parent.move(self.parent.pos() + event.globalPos() - self.dragPos)
            self.dragPos = event.globalPos()
            event.accept()

class MyGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # 버튼 생성
        self.button = QPushButton('클릭하세요', self)

        # 레이아웃 생성
        layout = QVBoxLayout()
        layout.addWidget(self.button)

        # 타이틀 바 생성
        self.titleBar = TitleBar(self)

        # 위젯에 레이아웃 및 타이틀 바 설정
        mainLayout = QVBoxLayout()
        mainLayout.addWidget(self.titleBar)
        mainLayout.addLayout(layout)
        mainLayout.setContentsMargins(0, 0, 0, 0)
        self.setLayout(mainLayout)

        # 윈도우 크기 및 제목 설정
        self.setGeometry(200, 100, 600, 400)  # 위치 (200, 100), 크기 600x400으로 변경
        self.setWindowTitle('Dark Mode PyQt 예제')

        # 윈도우 바 숨기기
        self.setWindowFlags(self.windowFlags() | Qt.FramelessWindowHint)

        # 스타일 시트 적용
        self.setStyleSheet("""
            QWidget {
                background-color: #272822;
                color: #f8f8f2;
                font-family: Arial, sans-serif;
            }
            QPushButton {
                background-color: #6272a4;
                color: #f8f8f2;
                border-radius: 5px;
                padding: 10px;
            }
            QPushButton:hover {
                background-color: #818eae;
            }
        """)

        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    app.setWindowIcon(QIcon("icon.png"))  # 아이콘 설정 (필요시)
    my_gui = MyGUI()
    sys.exit(app.exec_())