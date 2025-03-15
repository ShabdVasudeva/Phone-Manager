package apw.android.phonemanager;

class CPU{
    companion object{
        init{
            System.loadLibrary("systemutils")
        }
        external fun getCPUName(): String
        external fun getCPUCores(): Int
        external fun getCPUArch(): String
        fun getCPUAbi(): String{
            return Build.SUPPORTED_ABIS.joinToString(", ")
        }
    }
}