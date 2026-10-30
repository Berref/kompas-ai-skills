# ksIsSlaveSpcOpened - Проверить, открыто ли окно спецификации в подчиненном режиме

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksmodulespecification.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksismodulespecificationactive.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksIsSlaveSpcOpened](ksdocument2d_ksisslavespcopened.html).

Синтаксис:

int ksIsSlaveSpcOpened (reference doc);

Входные параметры:

doc | \- указатель на документ.  
---|---  
  
Возвращаемое значение:

0 | \- окно спецификации в Slave режиме не открыто,  
---|---  
1 | \- окно спецификации в Slave режиме открыто,  
2 | \- окно спецификации в Slave режиме открыто и активно.  
  
Примечание.

Если doc = 0, метод вызывается для активного документа.

Подразделы:

(отсутствуют)
