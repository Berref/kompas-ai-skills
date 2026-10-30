# ksChangeObjectInLibRequest - Изменить фантом или компоненты команд

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kschangeobjectinlibrequestw.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kscalcrasterscalew.html "К предыдущему разделу")  
---|---  
  
[Пример...](kschangeobjectinlibrequest_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksChangeObjectInLibRequest](ksdocument2d_kschangeobjectinlibrequest.html).

Синтаксис:

int ksChangeObjectInLibRequest (RequestInfo *info, void *phantom);

Входные параметры:

info | \- указатель на область памяти для замены состава команд,  
---|---  
phantom | \- указатель на [структуру управления фантомом.](structphantom.html)  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Во время работы функций [Cursor](cursor.html) и [Placement](placement.html) может возникнуть необходимость изменить фантом или компоненты команд. Функция ksChangeObjectInLibRequest позволяет передать изменения в цикл Cursor и Placement. Это может понадобиться для отработки команд пользовательских инструментальных панелей. Предварительно нужно убедиться, что вызов Cursor и требование к Cursor передаются в одном документе. Если какой-либо указатель равен 0, соответствующий параметр не используется. Если оба параметра равны 0, процессы Cursor и Placement прерываются. Это аналогично нажатию Esc.

После завершения функции, вызвавшей останов процесса, управление будет передано в Cursor или Placement, а затем в функцию пользователя, которая вызывала Cursor или Placement.

2\. При использовании Unicode следует использовать функцию [ksChangeObjectInLibRequestW](kschangeobjectinlibrequestw.html).

Подразделы:

(отсутствуют)
