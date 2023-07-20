from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QVBoxLayout, QLabel
from PyQt5 import uic
from PyQt5.QtChart import QChartView, QValueAxis, QLineSeries
from PyQt5.QtCore import pyqtSignal, QPointF


class MainWindow:
    def __init__(self, ui_filename):
        self._ui = uic.loadUi(ui_filename)
        self._ui.setWindowTitle("水质检测系统")
        self._ui.setWindowIcon(QIcon("./icon.ico"))

        # 光谱折线图初始化
        self.light_series = QLineSeries()
        self.light_series.setName("光谱数据")
        self.light_series_list = [QPointF(0, 6), QPointF(1, 9), QPointF(2, 2)]
        self.light_series.append(self.light_series_list)

        # 初始化 X 轴
        self._x_aix = QValueAxis()
        self._x_aix.setRange(0, 200)
        self._x_aix.setLabelFormat("%d")
        self._x_aix.setTickCount(11)
        self._x_aix.setMinorTickCount(0)

        # 初始化 Y 轴
        self._y_aix = QValueAxis()
        self._y_aix.setRange(0, 500)
        self._y_aix.setLabelFormat("%d")
        self._y_aix.setTickCount(11)
        self._y_aix.setMinorTickCount(0)

        # 创建图表
        self._chart_view = QChartView(self._ui.centralwidget)
        # 设置表格大小
        # self.chart_view.setGeometry(0, 0, self.ui.centralwidget.width(), self.ui.centralwidget.height())
        # 添加折线
        self._chart_view.chart().addSeries(self.light_series)
        # 设置 XY 轴
        self._chart_view.chart().setAxisX(self._x_aix)
        self._chart_view.chart().setAxisY(self._y_aix)
        self._ui.centralwidget.layout().addWidget(self._chart_view)

        # 标题权重
        self._ui.centralwidget.layout().setStretch(0, 1)
        # 数据权重
        self._ui.centralwidget.layout().setStretch(1, 2)
        # 表格权重
        self._ui.centralwidget.layout().setStretch(2, 1)
        self._ui.centralwidget.layout().setStretch(3, 5)

    # 显示界面
    def show(self):
        self._ui.show()

    # 设置界面显示数据
    def set_sensor_data(self, ph, temp, tre):
        self._ui.ph_value.setText(str(ph))
        self._ui.temp_value.setText(str(temp))
        self._ui.tre_value.setText(str(tre))

    # 更新光谱数据
    def update_light_chart(self, data):
        self.light_series.clear()
        self._chart_view.chart().removeSeries(self.light_series)
        self.light_series_list.clear()
        for i in range(0, len(data)):
            self.light_series_list.append(QPointF(i, data[i]))
        self.light_series.append(self.light_series_list)
        # 添加折线
        self._chart_view.chart().addSeries(self.light_series)
