# ksTextEx - Создать многострочный текст по структуре параметровTextParam

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](kstrimcurve.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](kssymmetryobj.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksTextEx](ksdocument2d_kstextex.html).

Синтаксис:

reference ksTextEx (TextParam * txtParam, int align);

Входные параметры:

txtParam | \- указатель на структуру [TextParam](structtextparam.html) параметров текста,  
---|---  
align | \- выравнивание текста: 0 - слева, 1 - по центру, 2 - справа, 3 - по ширине, -1 установить выравнивание как у стиля текста.  
  
Возвращаемое значение:

указатель на созданный тест | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
См. также структуру параметров [TextParam](structtextparam.html)

Подразделы:

(отсутствуют)
