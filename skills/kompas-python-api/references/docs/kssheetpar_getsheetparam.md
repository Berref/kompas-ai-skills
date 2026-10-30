# GetSheetParam - Получить указатель на интерфейс параметров листа документа ksStandartSheet или ksSheetSize

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейсы параметров формата и компоновки чертежа ](ce1717197.html) > [Оформление (Интерфейс ksSheetPar) ](kssheetpar.html) > [ksSheetPar - методы ](kssheetpar_methods.html) |  Scroll [ [ [ ](kssheetpar_init.html "К следующему разделу")](kssheetpar_methods.html "На уровень выше")](kssheetpar_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssheetpar.html)

Синтаксис Automation:

LPDISPATCH GetSheetParam();

Возвращаемое значение:

| \- указатель на интерфейс параметров листа документа [ksStandartSheet](ksstandartsheet.html) (для стандартного листа) или [ksSheetSize](kssheetsize.html) (для нестандартного листа).  
---|---  
  
Примечание:

Тип возвращаемого интерфейса определяется значением параметра type из параметров документа [ksDocumentParam](ksdocumentparam.html).

Подразделы:

(отсутствуют)
