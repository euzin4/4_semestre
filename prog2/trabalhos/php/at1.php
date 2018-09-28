<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Exemplo</title>
	</head>
	<body>
		<?php
			function horario(){
				$hora = date('G');
				if($hora >= 0 && $hora < 7 ){
				    echo "Boa Madrugada ";
				}else if($hora >= 7 && $hora < 12){
				    echo "Bom Dia!";
				}else if($hora >= 12 && $hora < 18){
				    echo "Boa Tarde!";
				}else{
				    echo "Boa noite!";
				}
			}
			function diaSemana(){
				$dia = date('D');
				echo "<br>Hoje é ";
				if($dia == 'sun'){
				    echo "Domingo ";
				}else if($dia == 'Mon'){
				    echo "Segunda-feira ";
				}else if($dia == 'Tue'){
				    echo "Terça-feira ";
				}else if($dia == 'Wed'){
				    echo "Quarta-feira ";
				}else if($dia == 'Thu'){
				    echo "Quinta-feira ";
				}else if($dia == 'Fri'){
				    echo "Sexta-feira ";
				}else{
				    echo "Sábado ";
				}
			}
			horario();
			diaSemana();

		?>
	</body>
</html>
