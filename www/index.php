<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="windows-1251">
        <title>Document</title>
    </head>
    <body>
        <h1>Привет</h1>
        <?php
            $zero = "<?";
            $one = 1;
            if(strval(strpos($zero,"<?")) != "") echo 1;
            if($one == "") echo 2;
            if(strval($zero) == "") echo 3;
            if($zero === "") echo 4;
        ?>
    </body>
</html>




