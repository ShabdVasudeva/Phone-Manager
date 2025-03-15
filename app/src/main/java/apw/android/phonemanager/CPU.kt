package apw.android.phonemanager;

import android.os.Build

object CPU{
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