# Python GUI PyQt5 설치
#pip install PyQt5
# OpenCV 설치
#pip install opencv-python
import sys
from PyQt5.QtWidgets import QApplication, QLabel, QMainWindow, QVBoxLayout, QWidget
from PyQt5.QtGui import QImage, QPixmap
from PyQt5.QtCore import QTimer
import cv2

class VideoStream(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Video Stream")
        self.setGeometry(100, 100, 800, 600)

        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)

        self.video_label = QLabel()
        layout = QVBoxLayout()
        layout.addWidget(self.video_label)
        self.central_widget.setLayout(layout)

        self.video_cap = cv2.VideoCapture(0)
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_frame)
        self.timer.start(30)  # Update frame every 30 milliseconds

    def update_frame(self):
        ret, frame = self.video_cap.read()
        if ret:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            h, w, ch = frame.shape
            bytes_per_line = ch * w
            q_img = QImage(frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(q_img)
            self.video_label.setPixmap(pixmap)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = VideoStream()
    window.show()
    sys.exit(app.exec_())
