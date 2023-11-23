<?php
// From chatGPT
$servername = "your_servername";
$username = "your_username";
$password = "your_password";
$database = "your_database";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $database);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
// Example query
$query = "SELECT * FROM your_table WHERE column_name LIKE '%$searchTerm%'";
$result = mysqli_query($conn, $sql);

if ($result) {
    // Process the result set
    while ($row = mysqli_fetch_assoc($result)) {
        echo "ID: " . $row["id"] . " - Name: " . $row["name"] . "<br>";
    }
} else {
    echo "Error: " . mysqli_error($conn);
}
// Close connection
mysqli_close($conn);
?>

