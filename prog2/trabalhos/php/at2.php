<!DOCTYPE html>
<html>
<head>
	<title>Atividade PHP</title>
	<style type="text/css">
		table, tr, td, th{
			border: 1px solid black;
			text-align: center;
		}
		th{
			background-color: grey;
		}
		td{
			padding: 0 15px;
		}
	</style>
</head>
<body>
	<?php
		function horario(){
			$hora = date('G');
			if($hora >= 0 && $hora < 7 ){
			    echo "Boa Madrugada ";
			}else if($hora >= 7 && $hora < 12){
			    echo "Bom Dia ";
			}else if($hora >= 12 && $hora < 18){
			    echo "Boa Tarde ";
			}else{
			    echo "Boa noite ";
			}
		}
		function diaSemana(){
			$dia = date('D');
			if($dia == 'sun'){
			    echo "Domingo ";
			}else if($dia == 'Mon'){
			    echo "Segunda ";
			}else if($dia == 'Tue'){
			    echo "Terça ";
			}else if($dia == 'Wed'){
			    echo "Quarta ";
			}else if($dia == 'Thu'){
			    echo "Quinta ";
			}else if($dia == 'Fri'){
			    echo "Sexta ";
			}else{
			    echo "Sábado ";
			}
		}
	?>
	<?php
		$alunos = array(
			array("nome" => "joao", "np1" => 7,"np2" => 5),
			array("nome" => "pedro", "np1" => 6,"np2" => 7),
			array("nome" => "maria", "np1" => 7,"np2" => 7),
			array("nome" => "jose", "np1" => 9,"np2" => 8),
			array("nome" => "ricardo", "np1" => 3,"np2" => 8),
			array("nome" => "ana", "np1" => 5,"np2" => 6),
			array("nome" => "guilherme", "np1" => 8,"np2" => 7),
			array("nome" => "renata", "np1" => 8,"np2" => 6),
			array("nome" => "juliana", "np1" => 6,"np2" => 8),
			array("nome" => "sara", "np1" => 5,"np2" => 4)
		);
		echo "<table>";
		echo "	<tr>
					<th>Nome</th>
					<th>NP1</th>
					<th>NP2</th>
				</tr>";
		foreach ($alunos as $item) {
			echo "<tr>
					<td>$item[nome]</td>
					<td>$item[np1]</td>
					<td>$item[np2]</td>
				  </tr>";
		}
		echo  "</table>";
	?>
</body>
</html>
