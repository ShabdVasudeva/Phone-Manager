package apw.android.phonemanager

object DeviceInfo{ 
    init{
        System.loadLibrary("systemutils")
    }
    external fun getDeviceName(): String
    external fun getCPUName(): String
}