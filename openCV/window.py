## Ex 3-8. 창을 화면의 가운데로.

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QDesktopWidget


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Real-time video filtering program')
        self.setFixedSize(1024, 768)         # 윈도우의 크기를 1024x768으로 고정
        self.center()                       # 윈도우 크기를 가운데에 위치
        self.show()

    def center(self):
        qr = self.frameGeometry()           # 프레임 위치
        cp = QDesktopWidget().availableGeometry().center()  #사용자 화면의 가운데 반환
        qr.moveCenter(cp)                   # 창의 위치를 화면 정가운데로 이동
        self.move(qr.topLeft())


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())
