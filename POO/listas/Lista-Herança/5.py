class Pagamento:
    def __init__(self, valor:float, data:str):
        self.__valor = valor
        self.__data = data

    @property
    def valor(self):
        return self.__valor

    @valor.setter
    def valor(self, v:float):
        self.__valor = v

    def processar_pagamento(self):
        print(f"Processando pagamento de R${self.valor:.2f} generico...")

class PagamentoCartao(Pagamento):
    def __init__(self, valor:float, data:str, ncartao:str, validade:str):
        super().__init__(valor, data)
        self.ncartao = ncartao 
        self.validade = validade

    def processar_pagamento(self):
        print(f"Pagamento de R${self.valor:.2f} realizado via cartao")

class PagamentoPix(Pagamento):
    def __init__(self, valor:float, data:str, chavePix:str):
        super().__init__(valor, data)
        self.chave = chavePix

    def processar_pagamento(self):
        print(f"Pagamento de R${self.valor:.2f} realizado via pix")

o1 = Pagamento(19.70, '20/3/2004')
o2 = PagamentoCartao(19.70, '20/3/2004', '24242942930242492', '24/03/2004')
o3 = PagamentoPix(19.70, '20/3/2004', '02042921')

o1.processar_pagamento()
o2.processar_pagamento()
o3.processar_pagamento()
