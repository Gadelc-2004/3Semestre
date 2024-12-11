class Midia:
    quantidade = 0 #atributo de classe
    def __init__(self, titulo:str, autor:str, ano:int):
        self.titulo = titulo
        self.autor = autor
        self.ano = ano
        Midia.quantidade += 1

    def imprime_dados(self):
        print(f"Midia({self.titulo}, {self.autor}, {self.ano})")

class Livro(Midia):
    def  __init__(self, titulo:str, autor:str, ano:int, paginas:int, editora:str):
    #self.titulo = titulo
    #self.autor = autor
    #self.ano = ano 
        super().__init__(titulo, autor, ano)
        self.paginas = paginas
        self.editora = editora
    pass

class Filme(Midia):
    def __init__(self, titulo:str, autor:str, ano:int, diretor:str, duracao:int):
        super().__init__(titulo, autor, ano)
        self.diretor = diretor
        self.duracao = duracao
    pass

class Musica (Midia):
    duracao_total = 0
    def __init__(self, titulo:str, autor:str, ano:int, album:str, duracao:float):
        super().__init__(titulo, autor, ano)
        self.album = album
        self.duracao = duracao
        Musica.duracao_total += duracao

    pass

m1 = Midia(titulo = 'bla', autor = 'fulano', ano = 2024)
m1.imprime_dados()
print(m1)

l1 = Livro(titulo = 'aaaaaa', autor = 'oda', ano = 1999, paginas = 1000, editora = 'SJ')
l1.imprime_dados()
print(l1)

m1 = Musica(titulo = 'rainha carmesim', autor 'kaito', ano = 2022, album = 'none', duracao = 4.5)
print(m1)

print(f"Quantidade de midia na biblioteca: {Midia.quantidade}")
print(f"Duracao de total das musicas: {Musica.duracao_total}")

