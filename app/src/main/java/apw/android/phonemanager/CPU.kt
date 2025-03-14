package apw.android.phonemanager;

object CPU{
    init {
        System.loadLibrary("systemutils")
    }

    external fun getCPUInfo(): CpuDataModel
}