import sys
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QDesktopWidget
from PyQt5.QtCore import Qt

from title_bar import MyTitleBar

class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Real-time video filtering program')
        self.setFixedSize(1024, 768)
        self.center()

        self.layout = QVBoxLayout()
        self.layout.addWidget(MyTitleBar(self))
        self.layout.setContentsMargins(0, 0, 0, 0)
        self.layout.addStretch(-1)
        self.setLayout(self.layout)

        self.setStyleSheet("""
            background-color: #212121;
            color: #ffffff;
            font-family: Arial, sans-serif;
        """)

        self.setWindowFlags(Qt.FramelessWindowHint)
        self.show()

    def center(self):
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
