<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Exemplo</title>
	</head>
	<body>
		<p><?php echo "Olá!<br>Eu sou um script PHP!";?></p>
		<p>Hoje é dia <?php echo date('d/m/y'); ?></p>
		<p>E agora são <?php echo date('h:i:s'); ?></p>
		<p>---------------------------------------------------</p>
		<?php $user = "visitante" ?>	<!--define um valor para variavel-->
		<p> <?php echo "olá $user" ?> </p>	<!--imprime o valor da variavel-->
	</body>
</html>
