<html>
    <head>
        <style>
            body {
                font-family: Arial, Helvetica, sans-serif;
                background-color: #F5F5F5;
                margin: 50px;
                display: flex;
                justify-content: center;
                text-align: center;
            }
            h1 {
                font-size: 40px;
				background-color: #FC5185;
				color: #f5f5f5;
			}
            .container {
			    width: 80%;
		    }
            select {
                width: 70%;
                height: 30px;
                margin: 5px;
            }
            form input[type="submit"] {
                height: 30px;
                border-color: #364F6B;
                background-color: #3FC1C9;
                border-radius: 5px;
            }
            .add-update {
                margin-top: 15px;
            }
            table {
                border-collapse: collapse;
                border: 2px solid #364F6B;
                width: 100%;
                margin: auto;
                text-align: left;
    		}
            td, th {
                border: 1px solid #FC5185;
                padding: 5px;
            }
        </style>
    </head>
    <body>
        <div class="container">
        <h1>View Marks</h1>
        <form action="" method="POST">
            <select name="ktu_id">
                <option value="none" selected disabled>SELECT STUDENT</option>
                <?php 
                    session_start();
                    $conn = mysqli_connect('localhost', 'root', '', 'registration');
                    if (!$conn) {
                        echo "Cannot connect!";
                    } else {

                        $sql = "SELECT ktu_id FROM users WHERE ktu_id != 'teacher'";
                        $result = mysqli_query($conn, $sql);
                        if ($result) {
                            while ($row = mysqli_fetch_assoc($result)) {
                                echo "<option value={$row['ktu_id']}>{$row['ktu_id']}</option>";
                            }
                        } else {
                            echo "No data.";
                        }

                    }
                ?>
            </select>
            <input type="submit" value="Get Marks" name="getmarks">
        </form>
    <?php 

        // Fetch marks from the database
        if ($_POST['getmarks']) {
            $ktu_id = $_POST['ktu_id'];
            $q = "SELECT * FROM marks WHERE ktu_id='$ktu_id'";
            $res = mysqli_query($conn, $q);
            if ($res) {
                if (mysqli_num_rows($res) > 0) {
                    echo "<table border=1>
                            <tr>
                                <th>Subject</th>
                                <th>Series 1</th>
                                <th>Series 2</th>
                                <th>Assignment 1</th>
                                <th>Assignment 2</th>
                                <th>Attendance</th>
                            </tr>";
                    while ($row = mysqli_fetch_assoc($res)) {
                        echo "<tr>
                                    <td>{$row['subject']}</td>
                                    <td>{$row['series1']}</td>
                                    <td>{$row['series2']}</td>
                                    <td>{$row['assignment1']}</td>
                                    <td>{$row['assignment2']}</td>
                                    <td>{$row['attendance']}</td>
                                </tr>";
                    }
                    echo "</table>";
                } else {
                    echo "<div>No marks added!</div><br>";
                }
            }
            if ($_SESSION['ktu_id'] == 'teacher') {
                echo "
                    <form method='post' action='update.php'>
                        <input type='hidden' value='{$ktu_id}' name='ktu_id'>
                        <input name='add-update' type='submit' class='add-update' value='Add or Update Marks'>
                    </form>
                ";
            }
        }
    ?>
</body>
