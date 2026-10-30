# ksGetWidthColumnSpc - Получить ширину колонки или текста в колонке

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksismodulespecificationactive.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgettuningspcstyleparamw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation - метод [ksSpecification::ksGetWidthColumnSpc](ksspecification_ksgetwidthcolumnspc.html).

Синтаксис Automation:

double ksGetWidthColumnSpc (int numColumn,

unsigned char cellOrText)

Входные параметры:

numColumn | \- номер колонки,  
---|---  
cellOrText | \- признак объекта, ширину которого требуется узнать: 1 - колонка, 0 - текст в колонке.  
  
Возвращаемое значение:

| ширина колонки или текста в колонке.  
---|---  
  
Примечание:

Номер колонки должен начинаться с единицы.

Подразделы:

(отсутствуют)
