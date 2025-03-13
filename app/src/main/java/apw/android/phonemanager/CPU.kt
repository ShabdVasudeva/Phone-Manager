package apw.android.phonemanager;

class CPU {
    companion object {
        init {
            System.loadLibrary("systemutils")
        }

        @JvmStatic external fun getCPUDetails(): String
        @JvmStatic external fun getCPUName(): String
        @JvmStatic external fun getNumCores(): Int
    }
}