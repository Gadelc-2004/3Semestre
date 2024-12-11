class cadastro:
    def __init__(self, login:str, senha:str):
        self.__login = login
        self.__senha = senha

    @property
    def login(self):
        return self.__login

    @property
    def senha(self):
        return self.__senha

    @login.setter
    def login(self, novoLogin):
        if(len(novoLogin) >= 5) and (len(novoLogin) <= 15):
            self.__login = novoLogin
        else:
            print("Tamanho de login invalido")
        return

    @senha.setter
    def senha(self, novaSenha):
        if(len(novaSenha) >= 8):
            self.__senha  = novaSenha
        else:
            print("Tamanho de senha invalido")
        return

p1 = cadastro("GabrielAlmeida", "DellaCroce")

print(p1.login, p1.senha)
p1.senha = "ester"

#print(p1.senha)
#p1.login("Gabriaaaa")
p1.login = "Gabriaaaa"
p1.senha = "lalaaaaaaaaa"

print(p1.login, p1.senha)
