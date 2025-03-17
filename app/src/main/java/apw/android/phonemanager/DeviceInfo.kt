package apw.android.phonemanager

object DeviceInfo{ 
    init{
        System.loadLibrary("systemutils")
    }
    external fun getDeviceName(): String
    external fun getBuildVersion(): String
    external fun getBasebandVersion(): String
    external fun getKernelVersion(): String
    external fun getZone(): String
    external fun getDisplayDpi(): String
    external fun getFingerprint(): String
}