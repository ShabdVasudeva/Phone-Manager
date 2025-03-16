package apw.android.phonemanager;

object GPU {
    init {
        System.loadLibrary("systemutils")
    }

    external fun getGPURenderer(): String
    external fun getGPUVendor(): String
    external fun getGPUVersion(): String
    external fun getGPUExtensions(): String
}