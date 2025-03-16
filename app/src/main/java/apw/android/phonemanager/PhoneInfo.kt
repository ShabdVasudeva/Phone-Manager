package apw.android.phonemanager

import android.os.Bundle
import androidx.activity.*
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.*
import androidx.compose.foundation.shape.*
import androidx.compose.foundation.*
import androidx.compose.material.icons.*
import androidx.compose.material.icons.filled.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.*
import android.content.*
import androidx.compose.ui.graphics.graphicsLayer
import androidx.compose.ui.text.font.FontWeight 
import androidx.activity.compose.*
import androidx.compose.ui.platform.*
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.ui.res.*
import androidx.compose.ui.text.style.*
import androidx.compose.ui.text.font.*
import androidx.compose.ui.unit.*
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.input.nestedscroll.*
import androidx.compose.ui.tooling.preview.Preview
import apw.android.phonemanager.ui.theme.MyComposeApplicationTheme
import apw.android.phonemanager.R
import apw.android.phonemanager.*

data class InfoData(
    val title: String,
    val subtitle: String
)

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun phoneInfoCompat(){
    val deviceName = DeviceInfo.getDeviceName()
    val cpuModel = CPU.getCPUName()
    val cpuCores = CPU.getCPUCores()
    val cpuArch = CPU.getCPUArch()
    val cpuMan = CPU.getCPUMan()
    val gpuRenderer = CPU.getGPURenderer()
    val values = listOf<InfoData>(
        InfoData("Device name", "$deviceName"),
        InfoData("CPU Manufacturer", "$cpuMan"),
        InfoData("CPU Model", "$cpuModel"),
        InfoData("CPU Cores", "$cpuCores"),
        InfoData("Architecture", "$cpuArch"),
        InfoData("Gpu Renderer", "$gpuRenderer")
    )
    Card(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        shape = RoundedCornerShape(15.dp),
    ){
        LazyColumn(
            verticalArrangement = Arrangement.spacedBy(10.dp),
            modifier = Modifier.padding(10.dp).fillMaxSize()
        ){
            items(values){ info ->
                Column(
                    verticalArrangement = Arrangement.Center
                ){
                    Text(
                        text = info.title,
                        fontSize = 17.5.sp,
                        fontWeight = FontWeight.Bold
                    )
                    Text(
                        text = info.subtitle,
                        fontSize = 12.sp
                    )
                }
            }
        }
    }
}
