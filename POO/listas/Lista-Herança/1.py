class Funcionario:
    def __init__(self, nome:str, cpf:str, salario:float, departamento:str):
        self.__nome = nome
        self.__cpf = cpf
        self.__salario = salario
        self.__departamento = departamento

    def __str__(self) -> str:
        return f"Nome: {self.__nome}\nCPF: {self.__cpf}\nSalario: {self.__salario}\nDepartamento: {self.__departamento}\n"

    @property
    def nome(self) -> str:
        return self.__nome
    @property
    def cpf(self) -> str:
        return self.__cpf
    @property
    def salario(self) -> float:
        return self.__salario
    @property
    def departamento(self) -> str:
        return self.__departamento

    @nome.setter
    def nome(self, n:str):
        self.__nome = n

    @cpf.setter
    def cpf(self, nc:str):
        self.__cpf = nc

    @salario.setter
    def salario(self, s:float):
        self.__salario = abs(float(s))

    @departamento.setter
    def departamento(self, d: str):
        self.__departamento = d

    def bonificar(self):
        if isinstance(self, Gerente):
            self.salario += self.salario * 0.15
        else:
            self.salario += self.salario * 0.1

class Gerente(Funcionario):
    def __init__(self, nome:str, cpf:str, salario:float, departamento:str, senha:str, nf:int):
        super().__init__(nome, cpf, salario, departamento)
        self.__senha = senha
        self.__nf = nf

    @property
    def senha(self) -> str:
        return self.__senha
    @property
    def nf(self) -> int:
        return self.__nf

    @senha.setter
    def senha(self, ns):
        self.__senha = ns

    @nf.setter
    def nf(self, n):
        self.__nf = abs(n)

    def autenticar_senha(self, s:str) -> bool:
        if(self.senha == s):
           return True
        return False

f1 = Funcionario("Ester PP", '42040302450', 1000.0, "Eletrodomestico")
f2 = Gerente("Gabriel", '42040302450', 2000.0, "Adm", "24032004", 9)

print(f"Funcionario 1 antes da bonificacao:\n{f1}")
f1.bonificar()
print(f"Funcionario 1 apos a bonificacao:\n{f1}")
print(f"Funcionario 2 antes da bonificacao:\n{f2}")
f2.bonificar()
print(f"Funcionario 2 apos a bonificacao:\n{f2}")
print("Teste do autenticar_senha, senha:24032004")
print("Teste com a tentativa de senha sendo 24032004: ", f2.autenticar_senha("24032004"))
print("Teste com a tentativa de senha sendo 2403: ", f2.autenticar_senha("2403"))
