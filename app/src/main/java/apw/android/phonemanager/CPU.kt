package apw.android.phonemanager;

object CPUInfo {
    init {
        System.loadLibrary("systemutils")
    }

    external fun getCPUInfo(): CpuDataModel
}