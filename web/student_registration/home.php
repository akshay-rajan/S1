<head>
	<style>
		.welcome {
			color: #FC5185;
		}
		body {
			background-color: #F5F5F5;
			margin: 50px;
			display: flex;
			justify-content: center;
			text-align: center;
		}
		table {
			border-color: #364F6B;
			width: 100%;
			margin: auto;
			text-align: left;
		}
		td, th {
			border-color: #364F6B;
			padding: 5px;
		}
		h2 {
			background-color: #FC5185;
			color: #f5f5f5;
		}
		.container {
			width: 80%;
		}
	</style>
</head>

<?php
	// Login 
	session_start();
	$conn = mysqli_connect('localhost', 'root', '', 'registration');
	if(!$conn)
	{
		echo "Cannot connect";
	} else if ($_POST['login']) {
		$ktuid = $_POST['ktuid'];
		$password = $_POST['password'];
		$q = "SELECT * FROM users WHERE ktu_id='$ktuid' AND password='$password'";
		$query = mysqli_query($conn, $q);
		if (mysqli_num_rows($query) > 0) {
			$_SESSION['ktu_id'] = $ktuid;
		} else {
			echo "<div>User not found!</div>";
		}
	}
?>
	
<body>
	<div class="container">
<?php 
	// DISPLAY DETAILS
	if ($_SESSION['ktu_id']) {
		$ktu_id = $_SESSION['ktu_id'];
		if ($ktu_id != 'teacher') {
			// Personal Details
			$sql = "SELECT * FROM users WHERE ktu_id='$ktu_id'";
			$result = mysqli_query($conn, $sql);

			$row = mysqli_fetch_assoc($result);
			echo "<h2>Student Details</h2>";
			echo "
				<table border=1 align='center' width='60%'>
					<tr>
						<td>KTU ID</td>
						<td>{$row['ktu_id']}</td>	
					</tr>
					<tr>
						<td>Name</td>
						<td>{$row['name']}</td>	
					</tr>
					<tr>
						<td>Age</td>
						<td>{$row['age']}</td>	
					</tr>
					<tr>
						<td>Gender</td>
						<td>{$row['gender']}</td>	
					</tr>
					<tr>
						<td>Phone Number</td>
						<td>{$row['phone']}</td>	
					</tr>
					<tr>
						<td>Semester</td>
						<td>{$row['sem']}</td>	
					</tr>
					<tr>
						<td>Roll No</td>
						<td>{$row['roll_no']}</td>	
					</tr>
					<tr>
						<td>Email</td>
						<td>{$row['email']}</td>	
					</tr>
				</table>";
		} else {
			// Teacher Login: Student Details Display
			$sql = "SELECT * FROM users WHERE ktu_id != '$ktu_id'";
			$result = mysqli_query($conn, $sql);
			echo "<h2>Student Details</h2>";
			echo "<table border=1 align='center' width='60%'>
					<tr>
						<th>KTU ID</th>
						<th>NAME</th>
						<th>AGE</th>
						<th>GENDER</th>
						<th>PHONE</th>
						<th>SEMESTER</th>
						<th>ROLL NO</th>
						<th>EMAIL</th>
					</tr>";
			while ($row = mysqli_fetch_assoc($result)) {
				echo "
					<tr>
						<td>{$row['ktu_id']}</td>
						<td>{$row['name']}</td>
						<td>{$row['age']}</td>
						<td>{$row['gender']}</td>
						<td>{$row['phone']}</td>
						<td>{$row['sem']}</td>
						<td>{$row['roll_no']}</td>
						<td>{$row['email']}</td>
					</tr>
				";
			}
			echo "</table>";
		}	
	} else {
		echo "<div class='welcome'><marquee behavior='alternate' direction='right' onmouseover='stop()' onmouseout='start()'><h1>Welcome!</h1></marquee></div>";
	}
	mysqli_close($conn);
?>
	</div>
</body>