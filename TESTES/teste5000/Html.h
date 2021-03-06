const char MainHtml[] PROGMEM = R"=====(
<html>
    <head>
        <script type="text/javascript" src="js/jquery-1.11.2.min.js"></script>
        <script type="text/javascript" src="js/underscore-min.js"></script>
        <script type="text/javascript" src="js/backbone-min.js"></script>
        <script type="text/javascript" src="js/joystick_view.js"></script>
    </head>
    <body>

    <script type="text/html" id="joystick-view">
    <canvas id="joystickCanvas" width="<%= squareSize %>" height="<%= squareSize %>" style="width: <%= squareSize %>px; height: <%= squareSize %>px;">
        </canvas>
    </script>

    <div id="joystickContent">
    </div>
    <div>
        x: <span id="xVal"></span><br/>
        y: <span id="yVal"></span><br/>
    </div>

    <script type="text/javascript">
        $(document).ready(function(){
            var joystickView = new JoystickView(150, function(callbackView){
                $("#joystickContent").append(callbackView.render().el);
                setTimeout(function(){
                    callbackView.renderSprite();
                }, 0);
            });
            joystickView.bind("verticalMove", function(y){
                $("#yVal").html(y);
            });
            joystickView.bind("horizontalMove", function(x){
                $("#xVal").html(x);
            });
        });
    </script>
    </body>
</html>
)=====";
