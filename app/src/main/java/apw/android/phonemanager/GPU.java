package apw.android.phonemanager;

public class GPU {
    static {
        System.loadLibrary("systemutils");
    }

    public native String getGPURenderer();
    public native String getGPUVendor();
    public native String getGPUVersion();
    public native String getGPUExtensions();
}