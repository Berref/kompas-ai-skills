unit Step4_1;
//******************************************************************/
//* 2. Процессы Cursor и Placement           - DrawRectCallBack,   */
//*                                            DrawRectNULL        */
//******************************************************************/

interface

uses Windows, SysUtils, LtDefine, LibTool, LibDB, LDefin2D;

//-------------------------------------------------------------------------------
// Используемые функции
//---
procedure DrawRectCallBack;
procedure DrawRectNULL;

function  CallBackP( com      : Integer;      // Идентификатор команды из окна команд
                     var x, y : Double;       // Координаты точки привязки
                     var angl : Double;       // Угол наклона
                     info     : PRequestInfo; // Указатель на область памяти для замены состава команд
                     phantom  : Pointer;      // Указатель на фантомную группу
                     _dynamic : Integer       // Признак динамического вызова
                   ): Integer; stdcall;

function  CallBackC( com      : Integer;      // Идентификатор команды из окна команд
                     var x, y : Double;       // Координаты точки привязки
                     info     : PRequestInfo; // Указатель на область памяти для замены состава команд
                     phantom  : Pointer;      // Указатель на фантомную группу
                     _dynamic : Integer       // Признак динамического вызова
                   ): Integer; stdcall;
//-------------------------------------------------------------------------------
implementation

var
 _type, flag : Integer;

//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
//---
function CallBackC( com      : Integer;      // Идентификатор команды из окна команд
                    var x, y : Double;       // Координаты точки привязки
                    info     : PRequestInfo; // Указатель на область памяти для замены состава команд
                    phantom  : Pointer;      // Указатель на фантомную группу
                    _dynamic : Integer       // Признак динамического вызова
                   ): Integer; stdcall;

var
  rub : PPhantom;                            // Указатель на параметры фантома
begin

  rub := PPhantom(phantom);

  case com  of
     1 : _type := com;                       // Команда 1
     2 : _type := com;                       // Команда 2
    -1 : begin                               // Поставить в модель
           MoveObj( rub^.type1.gr, x, y );   // Сместить группу

           if ( Abs(rub^.type1.ang) > 0.001 ) then
             RotateObj( rub^.type1.gr, x, y, rub^.type1.ang ); // Повернуть группу

           StoreTmpGroup( rub^.type1.gr );   // Поставить временную группу в вид
           ClearGroup( rub^.type1.gr );      // Очистить группу
         end;
  end;
  // Группа для фантома должна быть временная и обновляться при изменении вида отрисовки
  if  rub^.type1.gr > 0 then
    DeleteObj( rub^.type1.gr );   // Удаляем стагую группу

  // Отрисовываем новую группу
  rub^.type1.gr := NewGroup( 1 ); // Временная группа

  if ((flag=1) And (com=1)) Or ((flag=2) And (com=2)) then
    _type := 3;

  // Обновляется не только изображение но и меню для запроса
  case _type  of
    1: begin // Окружность
         Circle( 0, 0, 20, 1 );
         info^.commands := '!Квадрат !Треугольник';
         flag := 1;
       end;
    2: begin // Треугольник
         LineSeg( -10, 0, 10,  0, 1 );
         LineSeg(  10, 0,  0, 20, 1 );
         LineSeg( -10, 0,  0, 20, 1 );
         info^.commands := '!Окружность !Квадрат';
         flag := 2;
       end;
    3: begin // Квадрат
         LineSeg( -10,  0,  10,  0, 1 );
         LineSeg(  10,  0,  10, 20, 1 );
         LineSeg(  10, 20, -10, 20, 1 );
         LineSeg( -10, 20, -10,  0, 1 );
         info^.commands := '!Окружность !Треугольник';
         flag := 0;
       end;
  end;

  EndGroup();  // Создали группу

  CallBackC := 1;
end;

//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
//---
function CallBackP( com      : Integer;      // Идентификатор команды из окна команд
                    var x, y : Double;       // Координаты точки привязки
                    var angl : Double;       // Угол наклона
                    info     : PRequestInfo; // Указатель на область памяти для замены состава команд
                    phantom  : Pointer;      // Указатель на фантомную группу
                    _dynamic : Integer       // Признак динамического вызова
                  ): Integer; stdcall;
var
  rub : PPhantom;

begin
  rub := PPhantom (phantom);                 // Указатель на параметры фантома
  case  com of
     1 : _type := com;
     2 : _type := com;
    -1 : begin // Поставить в модель
           MoveObj( rub^.type1.gr, x, y );  // Сместить группу

          // В отлличии от Cursor угол приходит в виде параметра функции
          if ( Abs(angl) > 0.001 ) then
            RotateObj( rub^.type1.gr, x, y, angl ); // Повернем группу

          StoreTmpGroup( rub^.type1.gr );  // Поставить временную группу в вид
          ClearGroup( rub^.type1.gr );     // Очистить группу
      end;
  end;

  // Группа для фантома должна быть временная и обновляться при изменении вида отрисовки
  if rub^.type1.gr > 0 then
    DeleteObj( rub^.type1.gr );   // Удалить старую группу

  // Создать новую группу
  rub^.type1.gr := NewGroup( 1 ); // Временная группа
  if ((flag=1) And (com=1)) Or ((flag=2) And (com=2)) then
    _type := 3;

  // Обновляется не только изображение но и меню для запроса
  case  _type  of
    1 : begin
          Circle( 0, 0, 20, 1 );
          info^.commands := '!Квадрат !Треугольник ';
          flag := 1;
        end;
    2 : begin
          LineSeg( -10, 0, 10,  0, 1 );
          LineSeg(  10, 0,  0, 20, 1 );
          LineSeg( -10, 0,  0, 20, 1 );
          info^.commands := '!Окружность !Квадрат ';
          flag := 2;
        end;
    3 : begin
          LineSeg( -10,  0,  10,  0, 1 );
          LineSeg(  10,  0,  10, 20, 1 );
          LineSeg(  10, 20, -10, 20, 1 );
          LineSeg( -10, 20, -10,  0, 1 );
          info^.commands := '!Окружность !Треугольник ';
          flag := 0;
        end;
  end;

  EndGroup();

  CallBackP :=1;
end;

//-------------------------------------------------------------------------------
// Пример с использованием Cursor и Placemant c обратными функциями
//---
procedure DrawRectCallBack;
var
  info : RequestInfo;               // Параметры процесса
  rub  : Phantom;                   // Фантом
  x, y : Double;                    // Координаты точки вставки
begin
  _type := 1;

  FillChar( rub, sizeof(rub), 0 );
  rub.type1.scale := 1;             // Масштаб
  rub.phType      := 1;             // Тип фантома

  FillChar( info, sizeof(info), 0 );

  rub.type1.gr := NewGroup( 1 );    // Временная группа
    Circle( 0, 0, 20, 1 );          // Окружность
  EndGroup();

  info.commands := '!Квадрат !Треугольник';
  info.callBack := Addr(CallBackP); // Указываем адрес обратной функции для Placement
  Placement( Addr(info), x, y, rub.type1.ang, Addr(rub) );

  rub.type1.gr := NewGroup( 1 );    // Временная группа
    Circle( 0, 0, 20, 1 );          // Окружность
  EndGroup();

  info.callBack := Addr(CallBackC); // Указываем адрес обратной функции для Cursor
  ksCursor( Addr(info), x, y, Addr(rub) );

end;


//-------------------------------------------------------------------------------
// Пример с использованием Cursor и Placemant без обратных функций
// Разцица от предыдущего примера состоит в том, что цикл организован не внутри
// функции Cursor или Plecemant а снаружи. При этом на экране при каждом
// новом витке цикла будет гаснуть и снова всплывать окно меню.
//---
procedure DrawRectNULL;
var
  info : RequestInfo; // Параметры запроса
  rub  : Phantom;     // Фантом
  x, y : double ;     // координаты точки вставки
  j    : integer;

begin
  _type := 1;
  flag  := 1;
  j     := 1;
  FillChar( rub, sizeof(rub), 0 );
  rub.type1.scale := 1;  // Масштаб
  rub.phType      := 1;  // Тип фантома

  FillChar( info, sizeof(info), 0 );
  info.commands := 'Укажите точку привязки группы';

  while ( j <> 0 ) do
  begin
    if ( rub.type1.gr > 0 ) then
      DeleteObj( rub.type1.gr  );  // Удалить старую группу
    // Создать новую группу
    rub.type1.gr := NewGroup( 1 ); // Временная группа
    if( (flag=1) And (j=1)) Or ((flag=2) And (j=2) ) then
      _type := 3;

    case  _type  of
      1 : begin // Окружность
           Circle( 0, 0, 20, 1 );
           info.commands := '!Квадрат !Треугольник ';
           flag := 1;
          end;
      2 : begin  // Треугольник
            LineSeg( -10, 0, 10,  0, 1 );
            LineSeg(  10, 0,  0, 20, 1 );
            LineSeg( -10, 0,  0, 20, 1 );
            info.commands := '!Окружность !Квадрат ';
            flag := 2;
          end;
      3 : begin // Квадрат
            LineSeg( -10,  0,  10,  0, 1 );
            LineSeg(  10,  0,  10, 20, 1 );
            LineSeg(  10, 20, -10, 20, 1 );
            LineSeg( -10, 20, -10,  0, 1 );
            info.commands := '!Окружность !Треугольник ';
            flag := 0;
          end;
    end;

    EndGroup();

    // Запрос точки вставки и угла поворота группы
    j := Placement( Addr(info), x, y,
                    rub.type1.ang,
                    Addr(rub) );
//    j := Cursor(&info, &x, &y, &rub );  // Запрос точки вставки группы

    case  j of
      1 : _type := j;
      2 : _type := j;
     -1 : begin // Поставить в модель
            MoveObj( rub.type1.gr, x, y );                    // Сдвинуть группу

            if ( Abs(rub.type1.ang) > 0.001 ) then
              RotateObj( rub.type1.gr, x, y, rub.type1.ang ); // Повернуть группу

            StoreTmpGroup( rub.type1.gr );   // Поставить временную группу в вид
            ClearGroup( rub.type1.gr );      // Очистить группу
      end;
    end;
  end;
end;

end.