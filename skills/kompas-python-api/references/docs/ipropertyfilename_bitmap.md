# Bitmap - Рисунок кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyFileName ](ipropertyfilename.html) > [IPropertyFileName - свойства ](ipropertyfilename_props.html) |  Scroll [ [ [ ](ipropertyfilename_createopenbutton.html "К следующему разделу")](ipropertyfilename_props.html "На уровень выше")](ipropertyfilename_props.html "К предыдущему разделу")  
---|---  
  
Функция не поддерживается

[Интерфейс...](ipropertyfilename.html)

Тип данных: VARIANT (long или BSTR).

Синтаксис Automation:

iObject.Bitmap = Bitmap | Установить свойство ([* ](1.html))  
---|---  
iObject.SetBitmap (Bitmap) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->put_Bitmap (CreateOpenButton) | Установить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для записи.

2\. Позволяет задать изображение для кнопки вызова диалога открытия файла.

3\. Изображение можно задать в виде идентификаторов в ресурсе dll-модуля (тип данных long) или в виде полного пути к bmp-файлу рисунка (тип данных BSTR).

4\. Если изображение задается в виде идентификатора, то обязательно должен быть задан dll-модуль, в ресурсах которого лежат эти рисунки (см. [ResModule](ipropertyfilename_resmodule.html)).

Подразделы:

(отсутствуют)
