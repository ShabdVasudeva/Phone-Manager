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
    val values = listOf<InfoData>(
        InfoData("Device name", "$deviceName")
    )
    LazyColumn(
        modifier = Modifier.fillMaxWidth().padding(16.dp),
    ){
        items(values){ item->
            
        }
    }
}