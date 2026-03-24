<?php

session_start();
// $isLogin= $_SESSION['isLogin'];
// if ($isLogin== 1){
//     echo "user is logged in";
//     exit;
// }

if (!isset($_SESSION['userIsLogin']) || $_SESSION['userIsLogin']== false){
    header('Location: /login.php');
    exit;
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>HOMEPAGE</h1>
    <form action="logout.php" method="POST">
        <button>Logout</button>
    </form>
    
    
</body>
</html>