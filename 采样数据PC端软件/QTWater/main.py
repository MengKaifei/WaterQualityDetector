from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox
from main_window import MainWindow
from water_quality_testing_communication import WaterQualityComm
from PyQt5.QtCore import QTimer


def comm_timer_callback():
    PH, temp, TDS, data = water_quality_comm.get_data()
    main_window.set_sensor_data(PH, temp, TDS)
    main_window.update_light_chart(data)
    print("更新成功: PH = {}, TEMP = {}, TDS = {} ,DATA = {}".format(PH, temp, TDS, len(data)))


if __name__ == '__main__':
    app = QApplication([])

    # 构建通信对象
    water_quality_comm = WaterQualityComm("KEY", "KEY")

    # 构建通信定时器
    comm_timer = QTimer()

    # 构建UI
    main_window = MainWindow("main.ui")
    # 设置回调
    comm_timer.timeout.connect(comm_timer_callback)
    main_window.show()
    # 初始化UI
    comm_timer_callback()
    # 启动定时器
    comm_timer.start(5000)
    app.exec()

