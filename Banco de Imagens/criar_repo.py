import os

vestibulares = [
    "FUVEST", "UNICAMP", "UNESP", "ENEM", "ITA", "IME", "EINSTEIN", "FAMEMA", "FAMERP", "FATEC",
    "MACKENZIE", "MANDIC", "PUCCAMP", "PUCSP", "UEA", "UECE", "UEL", "UEM", "UEMG", "UEPG",
    "UERJ", "UERR", "UFAM", "UFG", "UFPR", "UFRGS", "UFRR", "UFSC", "UFSM"
]
anos = [2025, 2024, 2023, 2022, 2021, 2020, 2019, 2018, 2017, 2016, 2015]

base_path = "banco de Imagens"
os.makedirs(base_path, exist_ok=True)

for vestibular in vestibulares:
    vestibular_path = os.path.join(base_path, vestibular)
    os.makedirs(vestibular_path, exist_ok=True)
    for ano in anos:
        ano_path = os.path.join(vestibular_path, str(ano))
        os.makedirs(ano_path, exist_ok=True)
        for q in range(1, 91):
            questao_path = os.path.join(ano_path, f"questao-{q:02d}")
            os.makedirs(questao_path, exist_ok=True)

print("Estrutura criada com sucesso!")