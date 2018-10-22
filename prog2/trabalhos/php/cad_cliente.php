<?php
	include "includes/conexao.php";

	if(isset($_GET['confirmar'])){
		$nome = addslashes($_GET['nome']);
		$email = addslashes($_GET['email']);
		$endereco = addslashes($_GET['endereco']);
		$bairro = $_GET['bairro'];
		$perfil = $_GET['perfil'];
		$empresa = isset($_GET['empresa']) ? $_GET['empresa'] : "NULL";
		$login = $_GET['login'];
		$senha = $_GET['senha'];
		$senha2 = $_GET['senha2'];
		$concordo = isset($_GET['concordo']) ? "checked" : '';
		$senhaCripto = md5($senha);
			    
		$erros = array();
		//nome
		if(empty($nome))
			$erros[] = "O nome do produto não pode ser vazio";
		//email
		if(empty($email))
			$erros[] = "Email inválido";
		elseif(!filter_var($email, FILTER_VALIDATE_EMAIL))
			$erros[] = "Formato de email incorreto";
		//endereço
		if(empty($endereco))
			$erros[] = "Preencha o campo endereço";
		//bairro
		if(empty($bairro))
			$erros[] = "Selecione um bairro";
		//login
		if (strlen($login) < 6)
	    	$erros[] = "O login deve possuir pelo menos 6 caracteres";
	    //senha
	    if (strlen($senha) < 6)
	    	$erros[] = "A senha deve possuir pelo menos 6 caracteres";
	    if (strlen($senha) >= 6 && $senha != $senha2)
	    	$erros[] = "As senhas não são iguais";
	    //concordo
	    if (!isset($_GET['concordo']))
	    	$erros[] = "Você deve concordar com os termos de uso para prosseguir";

		if (count($erros) == 0){ // nenhum erro encontrado
		 	$sql = "INSERT INTO cliente (nome, email, endereco, bairro, perfil, nomeEmpresa, login, senha) VALUES ('$nome', '$email', 
		 	'$endereco', '$bairro', '$perfil', '$empresa', '$login', '$senhaCripto')";
			$resultado = mysqli_query($conexao, $sql);
			if($resultado){
				$mensagem = "O cadastro foi efetuado com sucesso";
			}
			else{
				$mensagem = "Erro. O cadastrado não foi efetuado. ";
				$mensagem .= mysqli_error($conexao); // para debug
			}
		}
	}
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta charset="utf-8">
	<title>Rent a Tool</title>
	<link rel="stylesheet" type="text/css" href="css/rent.css">
	<link rel="stylesheet" type="text/css" href="css/forms.css">
	<link href="https://fonts.googleapis.com/css?family=Lobster" rel="stylesheet"> <!-- web font Lobster -->
</head>
<body>
	<!-- cabeçalho -->
	<header>
		<p class="carrinho"><a href="#">Meu carrinho <img src="img/cart.png" width="32"></a></p>
		<h1>Rent a Tool</h1>
		<p id="exibeMenu">Menu</p>
		<nav class="menu-opcoes">    
			<ul>
				<li><a href="#">Minha Conta</a></li>
				<li><a href="#">Programa de pontos</a></li>
				<li><a href="#">Consumo solidário</a></li>
				<li><a href="#">Quem somos</a></li>
				<li><a href="#">Ajuda</a></li>
			</ul>
		</nav>
	</header>
	<!-- fim cabeçalho -->

	<!-- area central com 3 colunas -->
	<div class="container">
		
		<section class="col-1">
			<section class="busca">
				<form>
					<input type="search" placeholder="Busca...">
					<button>OK</button>
				</form>
			</section>

			<section class="menu-categorias">
				<h2>Categorias</h2>
				<nav>
					<ul>
						<li><a href="#">Marcenaria</a></li>
						<li><a href="#">Jardinagem</a></li>
						<li><a href="#">Limpeza</a></li>
						<li><a href="#">Escritório</a></li>
						<li><a href="#">Mecânica</a></li>
					</ul>
				</nav>
			</section>
		</section>

		<section class="col-2">
			<h2>Cadastre-se</h2>
			<?php
				if (isset($mensagem)){
					echo "<p>$mensagem</p>";
				}
				else{ // carrega form
					if(isset($erros)){ //print dos erros
						echo "<ul>";
						foreach ($erros as $erro){
							echo "<li style='color: red;'>$erro</li>";
						}
						echo "</ul>";
					}
				
			?>
			<div>
				<form action="" method="GET" id="form-contato">
				    <div class="form-item">
				      <label for="nome" class="label-alinhado">Nome:</label>
				      <input type="text" id="nome" name="nome" size="50" placeholder="Nome completo">
				      <span class="msg-erro" id="msg-nome"></span>
				    </div>
				    <div class="form-item">
				      <label for="email" class="label-alinhado">E-mail:</label>
				      <input type="email" id="email" name="email" placeholder="fulano@dominio" size="50">
				      <span class="msg-erro" id="msg-email"></span>
				    </div>					    
				    <div class="form-item">
				      <label for="endereco" class="label-alinhado">Endereço:</label>
				      <input type="text" id="endereco" name="endereco" placeholder="Rua, número, complemento" size="50">
				      <span class="msg-erro" id="msg-endereco"></span>
				    </div>	
				    <div class="form-item">
				      <label for="bairro" class="label-alinhado">Bairro:</label>
				      <select name="bairro" id="bairro">
					    <option value="">Selecione o bairro</option>
					    <option value="centro">Centro</option>
					    <option value="efapi">Efapi</option>
					    <option value="presidente médice">Presidente Médici</option>
					    <option value="jardim itália">Jardim Itália</option>
					    <option value="maria goretti">Maria Goretti</option>
					  </select>
					  <span class="msg-erro" id="msg-bairro"></span>
				    </div>
				    <div class="form-item">
				      <label class="label-alinhado">Perfil:</label>
				      <label style="display: none;"><input type="radio" name="perfil" value="NULL" id="vazio" checked></label>
				      <label><input type="radio" name="perfil" value="cf" id="perfilC">Consumidor final</label>
				      <label><input type="radio" name="perfil" value="ps" id="perfilP">Prestador de serviço</label>
					  <span class="msg-erro" id="msg-perfil"></span>
				    </div>
				    <div class="form-item">
				      <label for="empresa" class="label-alinhado">Nome da empresa:</label>
				      <input type="text" id="empresa" name="empresa" 
				      value="<?=(isset($_GET['empresa'])) ? $_GET['empresa'] : '';?>">
				      <span id="mensagem-empresa"></span>
				      <span class="msg-erro" id="msg-empresa"></span>
				    </div>					    
				    <div class="form-item">
				      <label for="login" class="label-alinhado">Login:</label>
				      <input type="text" id="login" name="login" placeholder="Mínimo 6 caracteres">
				      <span class="msg-erro" id="msg-login"></span>
				    </div>				    
				    <div class="form-item">
				      <label for="senha" class="label-alinhado">Senha:</label>
				      <input type="password" id="senha" name="senha" placeholder="Mínimo 6 caracteres">
				      <span class="msg-erro" id="msg-senha"></span>
				    </div>
				    <div class="form-item">
				      <label for="senha2" class="label-alinhado">Repita a Senha:</label>
				      <input type="password" id="senha2" name="senha2" placeholder="Mínimo 6 caracteres">
				      <span class="msg-erro" id="msg-senha2"></span>
				    </div>
				    <div class="form-item">
				      <label class="label-alinhado"></label>
				      <label><input type="checkbox" id="concordo" name="concordo"> Li e estou de acordo com os termos de uso do site</label>
				      <span class="msg-erro" id="msg-concordo"></span>
				    </div>				    
				    <div class="form-item">
				    	<label class="label-alinhado"></label>
				    <input type="submit" id="botao" value="Confirmar" name="confirmar">
				    </div>
				</form>
			</div>	
			<?php
				}
			?>		
		</section>

		<aside class="col-3">
			<h2>Mais pedidos</h2>
			<!-- container de mais pedidos -->
			<div class="lista-produtos">				
				<!-- um produto -->
				<div class="produto">
					<a href="produto.html">
						<figure>
							<img src="img/produtos/lavadora.jpg" alt="miniatura1">
							<figcaption>Lavadora de alta pressão<span class="preco">R$ 20,00</span></figcaption>
						</figure>
					</a>
				</div> 
				<!-- fim produto -->
				<div class="produto">
					<a href="produto.html">
						<figure>
							<img src="img/produtos/projetor.jpg" alt="miniatura1">
							<figcaption>Projetor multimídia<span class="preco">R$ 20,00</span></figcaption>
						</figure>
					</a>
				</div>
				<div class="produto">
					<a href="produto.html">
						<figure>
							<img src="img/produtos/serra3.jpg" alt="miniatura1">
							<figcaption>Serra elétrica<span class="preco">R$ 20,00</span></figcaption>
						</figure>
					</a>
				</div> 	


			</div>
		</aside>
	</div>
	<!-- fim area central -->

	<!-- rodape -->
	<footer><p>Rent a Tool - Chapecó/SC</p>
		<ul class="social">
			<li><a href="http://facebook.com/rentatool"><img src="img/facebook.png" alt="Facebook"></a></li>
			<li><a href="http://twitter.com/rentatool"><img src="img/twitter.png" alt="Twitter"></a></li>
			<li><a href="http://plus.google.com/rentatool"><img src="img/googleplus.png" alt="Google+"></a></li>
		</ul>
		<div id="ajuda">Precisa de ajuda? <span id="fechar">x</span></div>
	</footer>
	<!-- fim rodape -->
	<script src="js/functions.js"></script>
	<script src="js/cad_cliente.js"></script>

</body>
</html>