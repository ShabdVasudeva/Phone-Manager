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

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            MyComposeApplicationTheme {
                Surface(modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background) {
                    mainScreen()
                }
            }
        }
    }
}

data class CardInfo(
    val title: String,
    val summary: String,
    val icon: @Composable () -> Unit,
    val intent: Intent
)

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun mainScreen(){
    var selectedScreen by remember {mutableStateOf("Manager")}
    val scrollBehavior = TopAppBarDefaults.exitUntilCollapsedScrollBehavior()
    val scrollState = rememberLazyListState()
    Scaffold(
        topBar = {
            LargeTopAppBar(
                title = {
                    Text(
                        "Phone Manager",
                        maxLines = 2,
                        overflow = TextOverflow.Ellipsis
                    )
                },
                colors = TopAppBarDefaults.largeTopAppBarColors(
                    containerColor = MaterialTheme.colorScheme.surface,
                    scrolledContainerColor = MaterialTheme.colorScheme.surfaceVariant
                ),
                scrollBehavior = scrollBehavior
            )
        },
        bottomBar = {
            BottomNavBar(selectedScreen){
                selectedScreen = it
            }
        },
        content = { innerPadding ->
            Box(
                modifier = Modifier.padding(innerPadding)
            ){
                when(selectedScreen){
                    "Manager" -> ManagerScreen()
                    "Info" -> InfoScreen()
                }
            }
        }
    )
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun ManagerScreen(){
    val context = LocalContext.current
    val intent1: Intent = Intent(context, BatteryActivity::class.java)
    val intent2: Intent = Intent(context, BatteryActivity::class.java)
    val values = listOf<CardInfo>(
        CardInfo("Battery", "Battery stats and management", {Icon(painter = painterResource(R.drawable.battery), contentDescription = "Battery")}, intent1),
        CardInfo("Storage", "Storage stats and management", {Icon(painter = painterResource(R.drawable.storage), contentDescription = "Storage")}, intent2)
    )
    val launcher = rememberLauncherForActivityResult(ActivityResultContracts.StartActivityForResult()) { }
    LazyColumn(
        verticalArrangement = Arrangement.spacedBy(10.dp),
        modifier = Modifier.padding(10.dp).fillMaxSize()
    ) {
        items(values) { info ->
            Card(
                modifier = Modifier.fillMaxWidth().height(95.dp).padding(horizontal = 16.dp),
                shape = RoundedCornerShape(15.dp),
                onClick = {
                    launcher.launch(info.intent)
                }
            ){
                Row(
                    modifier = Modifier.fillMaxSize().padding(16.dp),
                    verticalAlignment = Alignment.CenterVertically
                ){
                    info.icon()
                    Column(verticalArrangement = Arrangement.Center){
                        Text(
                            text = info.title,
                            fontSize = 19.sp,
                            modifier = Modifier.padding(start = 10.dp)
                        )
                        Text(
                            text = info.summary,
                            fontSize = 12.sp,
                            modifier = Modifier.padding(start = 10.dp)
                        )
                    }
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun InfoScreen() {
    Column(
        modifier = Modifier.fillMaxSize().padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Text("Phone Manager App", fontSize = 24.sp)
        Spacer(modifier = Modifier.height(10.dp))
        Text("Version: 1.0", fontSize = 18.sp)
        Spacer(modifier = Modifier.height(10.dp))
        Text("Developed by APW Android", fontSize = 18.sp)
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun BottomNavBar(selectedScreen: String, onScreenSelected: (String) -> Unit) {
    NavigationBar {
        NavigationBarItem(
            selected = selectedScreen == "Manager",
            onClick = { onScreenSelected("Manager") },
            icon = { Icon(painter = painterResource(R.drawable.main), contentDescription = "Manager") },
            label = { Text("Manager") }
        )
        NavigationBarItem(
            selected = selectedScreen == "Info",
            onClick = { onScreenSelected("Info") },
            icon = { Icon(painter = painterResource(R.drawable.info), contentDescription = "Phone Info") },
            label = { Text("Phone Info") }
        )
    }
}
