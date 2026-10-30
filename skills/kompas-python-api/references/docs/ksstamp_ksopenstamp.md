# ksOpenStamp - Открыть основную надпись

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Основная надпись (Интерфейс ksStamp) ](ksstamp.html) > [ksStamp - методы ](ksstamp_methods.html) |  Scroll [ [ [ ](ksstamp_kssetstampcolumntext.html "К следующему разделу")](ksstamp_methods.html "На уровень выше")](ksstamp_ksgetstampcolumntext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksstamp.html)

Аналог данного метода при использовании API экспортных функций - [OpenStamp](openstamp.html).

Синтаксис Automation:

long ksOpenStamp();

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод действителен для чертежа и спецификации.

Операторы [ksStamp::ksColumnNumber](ksstamp_kscolumnnumber.html) и [ksStamp::ksTextLin](ksstamp_kstextline.html), вводимые между операторами [ksStamp::ksOpenStamp](ksstamp_ksopenstamp.html) и [ksStamp::ksCloseStamp](ksstamp_ksclosestamp.html), принадлежат основной надписи.

ksStamp::ksColumnNumber определяет номер ячейки, куда помещать текcт.

Номера определены в соответствии с ГОСТом на данную основную надпись.

ksStamp::ksCloseStamp возвращает указатель на штамп.

Подразделы:

(отсутствуют)
