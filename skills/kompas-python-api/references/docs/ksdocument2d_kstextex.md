# ksTextEx - Создать многострочный текст

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksviewtosheet.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksspecificationonsheet.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksTextEx](kstextex.html).

Синтаксис Automation:

long ksTextEx (LPDISPATCH txtParam, long align);

Входные параметры:

txtParam | \- указатель на интерфейс [ksTextParam](kstextparam.html) параметров текста,  
---|---  
align | \- выравнивание текста: 0 - слева, 1 - по центру, 2 - справа, 3 - по ширине, -1 установить выравнивание как у стиля текста.  
  
Возвращаемое значение:

указатель на созданный текст | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
