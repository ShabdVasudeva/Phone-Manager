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
import androidx.compose.ui.text.style.*
import androidx.compose.ui.unit.*
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.input.nestedscroll.*
import androidx.compose.ui.tooling.preview.Preview
import apw.android.phonemanager.ui.theme.MyComposeApplicationTheme

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
    val icon: @Composable () -> Unit
)

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun mainScreen(){
    val values = listOf<CardInfo>(
        CardInfo("Battery", "battery management and stats", {Icon(imageVector = Icons.Filled.MoreVert, contentDescription = "Battery")}),
        CardInfo("Storage", "Storage stats and management", {Icon(imageVector = Icons.Filled.MoreVert, contentDescription = "Storage")})
    )
    val scrollBehavior = TopAppBarDefaults.exitUntilCollapsedScrollBehavior()
    Scaffold(
        modifier = Modifier.nestedScroll(scrollBehavior.nestedScrollConnection),
        topBar = {
            LargeTopAppBar(
                title = { Text("Phone Manager", maxLines = 1, overflow = TextOverflow.Ellipsis) },
                actions = {
                    IconButton(onClick = {}) {
                        Icon(
                            imageVector = Icons.Filled.MoreVert,
                            contentDescription = "Menu"
                        )
                    }
                },
                scrollBehavior = scrollBehavior
            )
        },
        content = { innerPadding ->
            LazyColumn(
                contentPadding = innerPadding,
                verticalArrangement = Arrangement.spacedBy(8.dp),
                modifier = Modifier.fillMaxSize()
            ) {
                items(values) { info ->
                    Card(
                        modifier = Modifier.fillMaxWidth().height(70.dp).padding(10.dp),
                        shape = RoundedCornerShape(topStart = 15.dp, topEnd = 15.dp, bottomStart = 5.dp, bottomEnd = 5.dp),
                        onClick = {}
                    ){
                        Row(
                            modifier = Modifier.fillMaxSize(),
                        ){
                            info.icon()
                            Column(verticalArrangement = Arrangement.Center){
                                Text(
                                    text = info.title,
                                    fontSize = 23.sp,
                                    modifier = Modifier.padding(start = 10.dp)
                                )
                                Text(
                                    text = info.summary,
                                    fontSize = 15.sp,
                                    modifier = Modifier.padding(start = 15.dp)
                                )
                            }
                        }
                    }
                }
            }
        }
    )
}
