<head>
	<style>
		button {
			width: 70px;
			height: 35px;
			background-color: #F5F5F5;
			margin: 0px;
		}
		form input[type="text"] {
			height: 35px;
			background-color: #F5F5F5;
		}
		form input[type="text"], form input[type="submit"], button {
			height: 35px;
			margin: 0px;
			border-radius: 10px;
		}
		form input[type="text"] {
			margin-top: 17px;
		}
		form input[type="submit"] {
			background-color: #364F6B;
			color: #F5F5F5;
		}
	</style>
</head>
<body style="background-color: #3FC1C9;">
	<div style="margin: 25px;">
		<h1>Student Registration</h1>
	</div>
	<table style="position: fixed;right: 0px;top:15px; margin-right: 5px;" cellpadding=5>
	<tr>
		<td>
			<?php 
				session_start();
				if ($_SESSION['ktu_id'])
				echo "Logged in: {$_SESSION['ktu_id']}";
			?>
		</td>
		<td>
			<form action="search.php" method="POST" target="home">
				<input type="text" name="subject" placeholder="Search a subject">
				<input type="submit" name="search" value="Search"> 
			</form>
		</td>
		<td><button><a href="home.php" target="home">Home</a></button></td>
		<td><button><a href="register.php" target="home">Register</a></button></td>
		<td>
			<?php
				if (!$_SESSION['ktu_id'])
					echo "<button><a href='login.php' target='home'>Login</a></button>";
				else 
					echo "<button><a href='logout.php' target='home'>Logout</a></button>";
			?>
		</td>
		<td><button><a href="marks.php" target="home">Marks</a></button></td>
	</tr>
	</table>
</body>
