<html>
    <head>
        <style>
            body {
                font-family: Arial, Helvetica, sans-serif;
                background-color: #F5F5F5;
                margin: 20px;
                display: flex;
                justify-content: center;
                text-align: center;
            }
            h1 {
                font-size: 40px;
				background-color: #FC5185;
				color: #f5f5f5;
			}
            table {
                width: 100%;
                margin: auto;
                text-align: left;
		    }
            td, th {
                padding: 5px;
            }
            .container {
                width: 60%;
            }
            form input[type="text"] {
                width: 100%;
                height: auto;
            }
            form input[type="submit"] {
				margin: auto;
				text-align: center;
				background-color: #FC5185;
                border-radius: 5px;
                border-color: #364F6B;
				width: 100%;
				height: 30px;
			}
            #back {
                margin: 30px;
                width: 100px;
                border-color: #364F6B;
                background-color: #3FC1C9;
                border-radius: 5px;
            }
        </style>
    </head>
    <body>
        <?php $ktu_id = $_POST['ktu_id']; ?>
        <div class="container">
            <h1>Update Marks</h1>
            <h3>Student: <?php echo $ktu_id ?></h3>
            <form action="" method="POST">
                <?php
                    session_start();
                    $conn = mysqli_connect('localhost', 'root', '', 'registration');
                    if (!$conn) {
                        echo "Cannot connect!";
                    } else {
                        $ktu_id = $_POST['ktu_id'];
                        echo "<input type='hidden' name='ktu_id' value='{$ktu_id}'>";
                    }
                ?>
                <table>
                    <tr>
                        <th>Subject</th>
                        <td><input type='text' name='subject'></td>
                    </tr>
                    <tr>
                        <th>Series 1</th>
                        <td><input type='text' name='series1'></td>
                    </tr>
                    <tr>
                        <th>Series 2</th>
                        <td><input type='text' name='series2'></td>
                    </tr>
                    <tr>
                        <th>Assignment 1</th>
                        <td><input type='text' name='assignment1'></td>
                    </tr>
                    <tr>
                        <th>Assignment 2</th>
                        <td><input type='text' name='assignment2'></td>
                    </tr>
                    <tr>
                        <th>Attendance</th>
                        <td><input type='text' name='attendance'></td>
                    <tr>
                        <td colspan="2"><input type='submit' value='Update Marks' name='update'></td>
                    </tr>
                </table>
            </form>
        <?php 
            // Add or Update Marks
            if ($_POST['update']) {
                $ktu_id = $_POST['ktu_id'];
                $subject = $_POST['subject'];
                $series1 = $_POST['series1'];
                $series2 = $_POST['series2'];
                $assignment1 = $_POST['assignment1'];
                $assignment2 = $_POST['assignment2'];
                $attendance = $_POST['attendance'];
                
                $sql = "SELECT * FROM marks WHERE ktu_id = '$ktu_id' AND subject = '$subject'";
                $result = mysqli_query($conn, $sql);
                if (mysqli_num_rows($result) > 0) {
                    // If the marks for this subject already present, update marks
                    $sql = "UPDATE marks SET series1 = $series1, series2 = $series2, assignment1 = $assignment1, assignment2 = $assignment2, attendance = $attendance WHERE ktu_id = '$ktu_id' AND subject = '$subject'";
                    $updated = mysqli_query($conn,$sql);
                    if ($updated) {
                        echo "<div>Marks updated successfully</div>";
                    } else {
                        echo "<div>Cannot update marks</div>";
                    }
                } else {
                    // Create a fresh entry in the table
                    $sql = "INSERT INTO marks VALUES ('$ktu_id', '$subject', $series1, $series2, $assignment1, $assignment2, $attendance)";
                    $inserted = mysqli_query($conn, $sql);
                    if ($inserted) {
                        echo "<div>Marks Added successfully!</div>";
                    } else {
                        echo "<div>Cannot insert marks</div>";
                    }
                }
            }
        ?>
        <div>
            <a href="marks.php"><button id="back">Back</button></a>
        </div>
        </div>
    </body>
</html>
