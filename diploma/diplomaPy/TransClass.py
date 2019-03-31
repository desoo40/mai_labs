class Trans:
##    step - счётчик времени 1=час (1 - 744)
##    type - CASH-IN, CASH-OUT, DEBIT, PAYMENT, TRANSFER
##    amount - сумма транзакции в местной валюте
##    nameOrig - клиент, который начал транзакцию
##    oldbalanceOrg - начальный баланс до транзакции
##    newbalanceOrig - новый баланс после транзакции
##    nameDest - клиент, который является получателем транзакции
##    oldbalanceDest 
##    newbalanceDest 
##    isFraud
##    isFlaggedFraud

    def __init__(self, step, ttype, amount, nameOrig, oldbalanceOrg, newbalanceOrig, nameDest, oldbalanceDest, newbalanceDest, isFraud, isFlaggedFraud):
        self.step = int(step)
        self.hour = int(step) % 24
        self.ttype = ttype
        self.amount = float(amount)
        self.nameOrig = nameOrig
        self.oldbalanceOrg = float(oldbalanceOrg)
        self.newbalanceOrig = float(newbalanceOrig)
        self.nameDest = nameDest
        self.oldbalanceDest = float(oldbalanceDest)
        self.newbalanceDest = float(newbalanceDest)
        self.isFraud = int(isFraud)
        self.isFlaggedFraud = int(isFlaggedFraud)
        
    def printMe(self):
        print(str(self.step) + "\t " +
              self.ttype + "\t " +
              str(self.amount)  + "\t " +
              self.nameOrig + "\t " +
              str(self.oldbalanceOrg) + "\t " +
              str(self.newbalanceOrig) + "\t " +
              self.nameDest + "\t " +
              str(self.oldbalanceDest) + "\t " +
              str(self.newbalanceDest) + "\t " +
              str(self.isFraud) + "\t " +
              str(self.isFlaggedFraud) + "\t")
        
    def ttypeToInt(self):
        if self.ttype =="CASH-IN":
            return 1
        if self.ttype =="CASH-OUT":
            return 2
        if self.ttype =="DEBIT":
            return 3
        if self.ttype =="PAYMENT":
            return 4
        if self.ttype =="TRANSFER":
            return 5
        return 0
