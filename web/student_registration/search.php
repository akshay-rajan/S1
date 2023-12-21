<html>
    <head>
        <style>
            body {
                background-color: #F5F5F5;
                margin: 50px;
                display: flex;
                justify-content: center;
    			text-align: center;
            }
            table {
                border-color: #364F6B;
                border-width: 3;
                width: 100%;
                margin: auto;
                text-align: left;
            }
            td, th {
                border-color: #364F6B;
                padding: 5px;
            }
            h1 {
                background-color: #FC5185;
                color: #f5f5f5;
            }
            .container {
                width: 80%;
            }
            #print {
                margin: 10px;
            }
            @media print {
                body {
                    font-size: 10px;
                }
                table {
                    width: 500px;
                }
                #print {
                    display: none;
                }
            }
        </style>
        <script>
            function printPage() {
                window.print();
            }
        </script>
    </head>
    <body>
    <div>
        <?php 
            $conn = mysqli_connect('localhost', 'root', '', 'registration');
            if (!$conn) {
                echo "Cannot connect";
            } else {

                // Fetch all student's name and marks of a particular subject
                $subject = $_POST['subject'];
                $sql = "SELECT * FROM users JOIN marks ON users.ktu_id = marks.ktu_id WHERE marks.subject = '$subject'";
                $result = mysqli_query($conn, $sql);
                if (!$result) {
                    echo "Cannot search!";
                } else {
                    if (mysqli_num_rows($result) > 0) {
                        echo "
                            <h1>{$subject} Internal Marks</h1>
                            <table border=1 align='center' width='100%'>
                                <tr>
                                    <th>KTU ID</th>
                                    <th>Name</th>
                                    <th>Series 1<br> (/50)</th>
                                    <th>Series 2 <br> (/50)</th>
                                    <th>Assignment 1 <br> (/12)</th>
                                    <th>Assignment 2 <br> (/12)</th>
                                    <th>Attendance <br> (%)</th>
                                    <th>Internal Marks <br> (/50)</th>
                                </tr>
                        ";
                        while ($row = mysqli_fetch_assoc($result)) {

                            // Calculate Internal Marks
                            $series = ($row['series1'] + $row['series2']) / 5;
                            $assignment = ($row['assignment1'] + $row['assignment2']) / 2;
                            $attendance_percentage = $row['attendance'];
                            if ($attendance_percentage >= 90) {
                                $attendance = 8;
                            } else if ($attendance_percentage >= 80) {
                                $attendance = 7;
                            } else if ($attendance_percentage >= 75) {
                                $attendance = 6;
                            } else {
                                $attendance = 0;
                            }
                            $internal = $series + $assignment + $attendance;

                            echo "<tr>
                                    <td>{$row['ktu_id']}</td>
                                    <td>{$row['name']}</td>
                                    <td>{$row['series1']}</td>
                                    <td>{$row['series2']}</td>
                                    <td>{$row['assignment1']}</td>
                                    <td>{$row['assignment2']}</td>
                                    <td>{$row['attendance']}</td>
                                    <td>{$internal}</td>
                                </tr>";
                        }
                        echo "</table>";
                    } else {
                        echo "<div><h2>No Marks Found!</h2></div>";
                    }
                }
            }
            ?>
            <div>
                <button onclick="printPage()" id="print">Print Page</button>
            </div>
        </div>
    </body>
</html>