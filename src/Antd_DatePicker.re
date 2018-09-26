[@bs.module] external datePicker: ReasonReact.reactClass = "antd/lib/date-picker";
[%bs.raw {|require("antd/lib/date-picker/style")|}];

/*
 COMMON
 --------------------
 allowClear	Whether to show clear button	boolean	true
 autoFocus	get focus when component mounted	boolean	false
 className	picker className	string	''
 dateRender	custom rendering function for date cells	function(currentDate: moment, today: moment) => React.ReactNode	-
 disabled	determine whether the DatePicker is disabled	boolean	false
 disabledDate	specify the date that cannot be selected	(currentDate: moment) => boolean	-
 dropdownClassName	to customize the className of the popup calendar	string	-
 getCalendarContainer	to set the container of the floating layer, while the default is to create a div element in body	function(trigger)	-
 locale	localization configuration	object	default
 mode	picker panel mode	time|date|month|year	'date'
 open	open state of picker	boolean	-
 placeholder	placeholder of date input	string|RangePicker[]	-
 popupStyle	to customize the style of the popup calendar	object	{}
 size	determine the size of the input box, the height of large and small, are 40px and 24px respectively, while default size is 32px	string	-
 style	to customize the style of the input box	object	{}
 onOpenChange	a callback function, can be executed whether the popup calendar is popped up or closed	function(status)	-
 onPanelChange	callback when picker panel mode is changed	function(value, mode)
 */

/*
 defaultValue	to set default date	moment	-
 disabledTime	to specify the time that cannot be selected	function(date)	-
 format	to set the date format, refer to moment.js	string	"YYYY-MM-DD"
 renderExtraFooter	render extra footer in panel	() => React.ReactNode	-
 showTime	to provide an additional time selection	object|boolean	TimePicker Options
 showTime.defaultValue	to set default time of selected date, demo	moment	moment()
 showToday	whether to show "Today" button	boolean	true
 value	to set date	moment	-
 onCalendarChange	a callback function, can be executed when the start time or the end time of the range is changing	function(dates: moment, moment, dateStrings: string, string)	?
 onChange	a callback function, can be executed when the selected time is changing	function(date: moment, dateString: string)	-
 onOk	callback when click ok button	function()	-
 */

let optBoolToOptJsBoolean =
  fun
  | None => None
  | Some(v) => Some(v);

let unwrapBool = v => Js.Undefined.fromOption @@ optBoolToOptJsBoolean(v);

let make =
    (
      ~allowClear=?,
      ~allowFocus=?,
      ~className=?,
      ~dateRender=?,
      ~disabled=?,
      ~disabledDate=?,
      ~dropdownClassName=?,
      ~getCalendarContainer=?,
      ~locale=?,
      ~mode=?,
      ~open_=?,
      ~placeholder=?,
      ~size=?,
      ~style=?,
      ~onOpenChange=?,
      ~onPanelChange=?,
      ~defaultValue=?,
      ~disabledTime=?,
      ~format=?,
      ~renderExtraFooter=?,
      ~showTime=?,
      ~showTimeDefaultValue=?,
      ~showToday=?,
      ~value=?,
      ~onCalendarChange=?,
      ~onChange=?,
      ~onOk=?,
      ~id=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=datePicker,
    ~props=
      Js.Undefined.{
        "allowClear": unwrapBool(allowClear),
        "allowFocus": unwrapBool(allowFocus),
        "className": fromOption(className),
        "dateRender": fromOption(dateRender),
        "disabled": unwrapBool(disabled),
        "disabledDate": fromOption(disabledDate),
        "dropdownClassName": fromOption(dropdownClassName),
        "getCalendarContainer": fromOption(getCalendarContainer),
        "locale": fromOption(locale),
        "mode": fromOption(mode),
        "open": unwrapBool(open_),
        "placeholder": fromOption(placeholder),
        "size": fromOption(size),
        "style": fromOption(style),
        "onOpenChange": fromOption(onOpenChange),
        "onPanelChange": fromOption(onPanelChange),
        "defaultValue": fromOption(defaultValue),
        "disabledTime": fromOption(disabledTime),
        "format": fromOption(format),
        "renderExtraFooter": fromOption(renderExtraFooter),
        "showTime": fromOption(showTime),
        "showTime.defaultValue": fromOption(showTimeDefaultValue),
        "showToday": unwrapBool(showToday),
        "value": fromOption(value),
        "onCalendarChange": fromOption(onCalendarChange),
        "onChange": fromOption(onChange),
        "onOk": fromOption(onOk),
        "id": fromOption(id),
      },
  );

module Locale = {
  module Lang = {
    [@bs.deriving abstract]
    type t =
      pri {
        placeholder: string,
        rangePlaceholder: array(string),
        today: string,
        now: string,
        backToToday: string,
        ok: string,
        clear: string,
        month: string,
        year: string,
        timeSelect: string,
        dateSelect: string,
        weekSelect: string,
        monthSelect: string,
        yearSelect: string,
        decadeSelect: string,
        yearFormat: string,
        dateFormat: string,
        dayFormat: string,
        dateTimeFormat: string,
        monthBeforeYear: bool,
        previousMonth: string,
        nextMonth: string,
        previousYear: string,
        nextYear: string,
        previousDecade: string,
        nextDecade: string,
        previousCentury: string,
        nextCentury: string,
      };
  };

  [@bs.deriving abstract]
  type t =
    pri {
      lang: Lang.t,
      timePickerLocale: Antd_TimePicker.Locale.t,
    };
};
