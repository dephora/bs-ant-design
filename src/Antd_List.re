[@bs.module] external reactClass: ReasonReact.reactClass = "antd/lib/list";
[%bs.raw {|require("antd/lib/list/style")|}];

[@bs.deriving jsConverter]
type position = [ | `top | `bottom | `both];

type pagination = {. "position": position};

/*
 column	column of grid	number	-
 gutter	spacing between grid	number	0
 size	Size of list	default | middle | small	default
 xs	<576px column of grid	number	-
 sm	?576px column of grid	number	-
 md	?768px column of grid	number	-
 lg	?992px column of grid	number	-
 xl	?1200px column of grid	number	-
 xxl	?1600px column of grid	number	-
 */

type grid = {
  .
  "column": int,
  "gutter": int,
  "size": string,
  "xs": int,
  "sm": int,
  "md": int,
  "lg": int,
  "xl": int,
  "xxl": int,
};

/*
 bordered	Toggles rendering of the border around the list	boolean	false
 footer	List footer renderer	string|ReactNode	-
 grid	The grid type of list. You can set grid to something like {gutter: 16, column: 4}	object	-
 header	List header renderer	string|ReactNode	-
 itemLayout	The layout of list, default is horizontal, If a vertical list is desired, set the itemLayout property to vertical	string	-
 loading	Shows a loading indicator while the contents of the list are being fetched	boolean|object (more)	false
 loadMore	Shows a load more content	string|ReactNode	-
 locale	i18n text including empty text	object	emptyText: 'No Data'
 pagination	Pagination config, hide it by setting it to false	boolean | object	false
 split	Toggles rendering of the split under the list item	boolean	true
 */

[@bs.obj]
external makeProps:
  (
    ~dataSource: array(ReasonReact.reactElement)=?,
    ~renderItem: ReasonReact.reactElement => ReasonReact.reactElement=?,
    ~bordered: bool=?,
    ~footer: ReasonReact.reactElement=?,
    ~grid: grid=?,
    ~header: ReasonReact.reactElement=?,
    ~itemLayout: string=?,
    ~loading: ReasonReact.reactElement=?,
    ~loadMore: ReasonReact.reactElement=?,
    ~locale: bool=?,
    ~pagination: pagination=?,
    ~split: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~dataSource=?,
      ~renderItem=?,
      ~bordered=?,
      ~footer=?,
      ~grid=?,
      ~header=?,
      ~itemLayout=?,
      ~loading=?,
      ~loadMore=?,
      ~locale=?,
      ~pagination=?,
      ~split=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~dataSource=?Js.Option.map((. b) => Array.of_list(b), dataSource),
        ~renderItem?,
        ~bordered?,
        ~footer?,
        ~grid?,
        ~header?,
        ~itemLayout?,
        ~loading?,
        ~loadMore?,
        ~locale?,
        ~pagination?,
        ~split?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

/*
 actions	The actions content of list item. If itemLayout is vertical, shows the content on bottom, otherwise shows content on the far right.	Array	-
 extra	The extra content of list item. If itemLayout is vertical, shows the content on right, otherwise shows content on the far right.	string|ReactNode	-

 */

module Item = {
  [@bs.module "antd/lib/list"] external reactClass: ReasonReact.reactClass = "Item";
  [@bs.obj]
  external makeProps: (~actions: array(ReasonReact.reactElement)=?, ~extra: ReasonReact.reactElement=?, unit) => _ =
    "";
  let make = (~actions=?, ~extra=?, children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(~actions?, ~extra?, ()), children);

  /*
   avatar	The avatar of list item	ReactNode	-
   description	The description of list item	string|ReactNode	-
   title	The title of list item	string|ReactNode	-
     */

  module Meta = {
    [@bs.module "antd/lib/list"] external reactClass: ReasonReact.reactClass = "Meta";
    [@bs.obj]
    external makeProps:
      (
        ~avatar: ReasonReact.reactElement=?,
        ~description: ReasonReact.reactElement=?,
        ~title: ReasonReact.reactElement=?,
        ~className: string=?,
        ~style: ReactDOMRe.style=?,
        unit
      ) =>
      _ =
      "";
    let make = (~avatar=?, ~description=?, ~title=?, ~className=?, ~style=?, children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props=makeProps(~avatar?, ~description?, ~title?, ~className?, ~style?, ()),
        children,
      );
  };
};
