import json
from tencentcloud.common import credential
from tencentcloud.common.profile.client_profile import ClientProfile
from tencentcloud.common.profile.http_profile import HttpProfile
from tencentcloud.common.exception.tencent_cloud_sdk_exception import TencentCloudSDKException
from tencentcloud.iotexplorer.v20190423 import iotexplorer_client, models


class WaterQualityComm:
    def __init__(self, secret_id, secret_key):
        try:
            # 实例化一个认证对象，入参需要传入腾讯云账户 SecretId 和 SecretKey，此处还需注意密钥对的保密
            # 代码泄露可能会导致 SecretId 和 SecretKey 泄露，并威胁账号下所有资源的安全性。以下代码示例仅供参考，建议采用更安全的方式来使用密钥，请参见：https://cloud.tencent.com/document/product/1278/85305
            # 密钥可前往官网控制台 https://console.cloud.tencent.com/cam/capi 进行获取
            cred = credential.Credential(secret_id, secret_key)
            # 实例化一个http选项，可选的，没有特殊需求可以跳过
            httpProfile = HttpProfile()
            httpProfile.endpoint = "iotexplorer.tencentcloudapi.com"

            # # 实例化一个client选项，可选的，没有特殊需求可以跳过
            clientProfile = ClientProfile()
            clientProfile.httpProfile = httpProfile
            # 实例化要请求产品的client对象,clientProfile是可选的
            self._client = iotexplorer_client.IotexplorerClient(cred, "ap-guangzhou", clientProfile)

            # 实例化一个请求对象,每个接口都会对应一个request对象
            self._req = models.DescribeDeviceDataRequest()
            params = {
                "ProductId": "5DOXOMOIXC",
                "DeviceName": "device1"
            }
            self._req.from_json_string(json.dumps(params))

        except TencentCloudSDKException as err:
            print(err)

    # 获取传感器数据
    def get_data(self):
        try:
            # 返回的resp是一个DescribeDeviceDataResponse的实例，与请求对象对应
            resp = self._client.DescribeDeviceData(self._req)
            # 输出json格式的字符串回包
            data_dict = json.loads(resp.Data)
            # PH值  温度值  浑浊度
            return data_dict['PH']['Value'], data_dict['Temperature']['Value'], data_dict['TDS']['Value'], data_dict['spectrum']['Value']
        except TencentCloudSDKException as err:
            print(err)
