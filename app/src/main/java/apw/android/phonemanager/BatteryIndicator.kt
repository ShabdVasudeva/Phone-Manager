package apw.android.phonemanager;

import androidx.compose.animation.core.animateFloatAsState
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.MaterialTheme
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp

@Composable
fun BatteryIndicator(batteryPercentage: Int) {
    val animatedProgress by animateFloatAsState(
        targetValue = batteryPercentage / 100f,
        label = "Battery Progress"
    )

    val batteryColor = when {
        batteryPercentage > 50 -> Color(0xFF4CAF50) // Green
        batteryPercentage > 20 -> Color(0xFFFFC107) // Yellow
        else -> Color(0xFFF44336) // Red
    }

    Box(
        modifier = Modifier
            .fillMaxWidth()
            .height(40.dp)
            .background(Color(0xFFBDBDBD), RoundedCornerShape(20.dp)) // Grey Background
    ) {
        Box(
            modifier = Modifier
                .fillMaxWidth(animatedProgress)
                .height(40.dp)
                .background(batteryColor, RoundedCornerShape(20.dp)), // Dynamic Battery Color
            contentAlignment = Alignment.Center
        ) {}
    }
}