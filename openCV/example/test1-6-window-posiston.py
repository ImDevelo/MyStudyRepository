## Ex 3-8. 창을 화면의 가운데로.

import sys
from PyQt5.QtWidgets import QApplication, QWidget, QDesktopWidget


class MyApp(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Centering')
        self.resize(500, 350)
        self.center()                       #가운데 위치
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
