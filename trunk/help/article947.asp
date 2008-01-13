<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head>
<meta http-equiv="content-type" content="text/html; charset=ISO-8859-1">



  <title>GameDev.net - OpenGL Texture Mapping: An Introduction</title>
  <link rel="stylesheet" href="article947_files/reference.css" type="text/css">
  <link rel="icon" href="http://www.gamedev.net/pics/gdicon.png" type="image/png">
</head><body leftmargin="0" topmargin="0" alink="#000000" background="article947_files/watermark.gif" bgcolor="#ffffff" link="#666699" marginheight="0" marginwidth="0" text="#000000" vlink="#666699"><script type="text/javascript" src="article947_files/spit.jsp"></script><script type="text/javascript" src="article947_files/chunks_002.jsp"></script><script type="text/javascript" src="article947_files/chunks.jsp"></script><script type="text/javascript" src="article947_files/chunks_003.jsp"></script><script type="text/javascript" src="article947_files/func_200712191457.js"></script><script type="text/javascript" src="article947_files/door.jsp"></script><script type="text/javascript" src="article947_files/tsc.jsp"></script>

<table border="0" cellpadding="3" cellspacing="0" width="100%">
  <tbody><tr>
    <td class="tblhdr">OpenGL Texture Mapping: An Introduction</td>
    <td class="tblhdr" align="right" nowrap="nowrap"><img src="article947_files/littleg.gif" align="absbottom" height="16" width="16">&nbsp;<a href="http://www.gamedev.net/"><span style="color: white; text-decoration: none;">GameDev.net</span></a></td>
  </tr>
  <tr>
    <td colspan="2" align="center">
<!-- Begin -  Site: GameDev.net Zone: GameDev.net variable width -->
<script language="javascript" type="text/javascript">
<!--
var browName = navigator.appName;
var SiteID = 1;
var browDateTime = (new Date()).getTime();
if (browName=='Netscape')
{
document.write('<s'+'cript lang' + 'uage="jav' + 'ascript" src="http://www.gamedev.net/banman/a.aspx?ZoneID=13&amp;Task=Get&amp;IFR=False&amp;Browser=NETSCAPE4&amp;PageID=55140&amp;SiteID=' + SiteID + '&amp;Random=' + browDateTime + '">'); document.write('</'+'scr'+'ipt>');
}
if (browName!='Netscape')
{
document.write('<s'+'cript lang' + 'uage="jav' + 'ascript" src="http://www.gamedev.net/banman/a.aspx?ZoneID=13&amp;Task=Get&amp;IFR=False&amp;PageID=55140&amp;SiteID=' + SiteID + '&amp;Random=' + browDateTime + '">'); document.write('</'+'scr'+'ipt>');
}
// --> 
</script><script language="javascript" src="article947_files/a.aspx"></script><!-- BEGIN RICH-MEDIA NETWORK CODE -->
<script language="JavaScript">
rnum=Math.round(Math.random() * 100000);

document.write('<scr'+'ipt src="http://www.burstnet.com/cgi-bin/ads/ad10166a.cgi/v=2.0S/sz=468x60A|728x90A/'+rnum+'/NI/RETURN-CODE/JS/"></scr'+'ipt>');

</script><script src="article947_files/a"></script><iframe src="article947_files/banman.aspx" marginwidth="0" marginheight="0" hspace="0" vspace="0" frameborder="0" height="90" scrolling="no" width="728"></iframe><img src="article947_files/blank.gif" align="right" height="0" width="0"><script language="JavaScript">var tcdacmd="dt";var ANBCH="573";</script><script src="article947_files/slf.js" language="JavaScript"></script><noscript><a href="http://www.burstnet.com/ads/ad10166a-map.cgi/ns/v=2.0S/sz=468x60A|728x90A/" target="_top">
<img src="http://www.burstnet.com/cgi-bin/ads/ad10166a.cgi/ns/v=2.0S/sz=468x60A|728x90A/" border="0" alt="Click Here"></a>
</noscript>
<!-- END BURST CODE -->

<noscript> <a
href="http://www.gamedev.net/banman/a.aspx?ZoneID=13&amp;Task=Click&amp;Mode=HTML&amp;SiteID=1&amp;PageID="
target="_blank"> <img
src="http://www.gamedev.net/banman/a.aspx?ZoneID=13&amp;Task=Get&amp;Mode=HTML&amp;SiteID=1&amp;PageID="
width="728" height="90" border="0" alt=""></a>
</noscript>
<!-- End -  Site: GameDev.net Zone: GameDev.net variable width --></td>
  </tr>
</tbody></table>
<table border="0" cellpadding="5" cellspacing="0" width="100%"><tbody><tr><td>

<center><span class="title">OpenGL Texture Mapping: An Introduction</span>
<br><span class="author">by Nate Miller</span></center>

<p>This article will cover the basics of texture mapping in OpenGL.
This includes the uploading of the texture to the video memory and the
application of the texture onto geometry. This article will not cover
the actual loading of the texture data itself. That is left up to the
reader. If you have prior experience in OpenGL texture mapping I
suggest that you pass on reading this article unless you would like to
refresh your memory. This document is aimed at the programmer who is
trying to get started with OpenGL texture mapping. Snippets of code
will be thrown in to clarify ideas and concepts.
</p><h1>Uploading Textures</h1>
<p>So you have some raw RGB image data in a buffer and you want to
apply it to your geometry in OpenGL? The first thing you have to do
before OpenGL can use this raw texture data is upload it to the video
memory. Once a texture is uploaded to the video memory it can be used
throughout the time in which your application is running. Before a
texture can be uploaded to the video memory there is some setup that
must take place so OpenGL knows what to do with the image data that is
passed to it. Below I will outline the order that certain calls need to
be made in order to upload your texture. Note that these calls should
be made once per texture when the application is started. Please check
the pseudo code below for a better idea.
</p><p></p><div align="center"><center>
<table border="0" cellpadding="4" cellspacing="2" width="100%">
    <tbody><tr>
        <td align="center" bgcolor="#808080"><p align="center"><font color="white"><b>glBindTexture</b></font></p></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0"><font color="black">The first thing that must take place in the process of uploading the texture is a call to <em>glBindTexture</em>. What <em>glBindTexture</em>
does is it tells OpenGL which texture "id" we will be working with. A
texture "id" is just a number that you will use to access your
textures. Here is a sample call. <blockquote><span class="code">glBindTexture(GL_TEXTURE_2D, 13);</span></blockquote>
This call will make texture that is associated with the ID of 13 the
active texture. Any calls that have to do with OpenGL texture mapping
will effect this texture. It is important that you remember this number
since it will be needed again later on to actually apply the texture to
geometry. </font></td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080"><font color="white"><b>glPixelStorei</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0"><font color="black">The <em>glPixelStorei</em> call tells OpenGL how the data that is going to be uploaded is aligned. A call to <em>glPixelSrotei</em> is shown below.
        <blockquote><span class="code">glPixelStorei(GL_UNPACK_ALIGNMENT, 1);</span></blockquote>
This call tells OpenGL that the pixel data which is going to be passed
to it is aligned in byte order, this means that the data has one byte
for each component, one for red, green and blue. Stick to the call
above unless you have some sort of exotic data which I highly doubt.
The alignment of data will probably change as you advance into OpenGL
texture mapping. </font></td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080"><font color="white"><b>glTexParameteri</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0"><font color="black">The <em>glTexParameteri</em>
sets the various parameters for the current OpenGL texture. The
parameters that are passed and their effects on the texture are an
advanced topic. If you would like to further research what each call
does please take a look at the links provided at the end of this
document. Each of these lines are important so make sure to get each in
your application. <blockquote><span class="code">glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);<br>
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);<br>
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);<br>
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);</span></blockquote>
Why did I leave out a description of what these do if they are so
important? The properties that you can change with these calls are
important to someone who would be more advanced. For someone who is
just learning they should be seen as the "voodoo" that makes things
work. Once you have a solid understanding of how texture mapping works
in OpenGL then you should take a look at these properties. </font></td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080"><font color="white"><b>glTexEnvf</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0"><font color="black">The <em>glTexEnvf</em>
call sets environment variables for the current texture. What this does
is tell OpenGL how the texture will act when it is rendered into a
scene. Below is a sample call which I use in my applications. <blockquote><span class="code">glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);</span></blockquote>
What this does is sets the active texture to GL_MODULATE. The
GL_MODULATE attribute allows you to apply effects such as lighting and
coloring to your texture. If you do not want lighting and coloring to
effect your texture and you would like to display the texture unchanged
when coloring is applied replace GL_MODULATE with GL_DECAL. </font></td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080"><font color="white"><b>glTexImage2D</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0"><font color="black">The <em>glTexImage2D</em>
call is our goal. This call will upload the texture to the video memory
where it will be ready for us to use in our programs. I am going to
explain this call parameter by parameter since it is so important to
what we are doing. </font><ul>
<font color="black">            <li><em>target</em> - The target of this call, it will always be GL_TEXTURE_2D.
            </li><li><em>level </em>-
The level of detail number, this should be left at 0 for our purposes.
Once you become more adept at OpenGL texture mapping this parameter
will be something that you might change. </li><li><em>internalformat</em> - Internal components
parameter. This tells OpenGL how many color components to represent
internally from the texture that is uploaded. There are many symbolic
constants for this parameter but the one which is most widely used is
GL_RGB; this constant is equal to 3. </li><li><em>width &amp; height</em> - The width and
height of the image data. These must be integers that are equal to
2n+2(border) for some integer n. What this basically means is that the
texture width and height must be a power of two
(2,4,8,16,32,63,128,256,512, etc). </li><li><em>border</em> - Image border, must be 0 or 1. I always use 0 in my code since I do not use image borders.
            </li><li><em>format</em>
- Format of the pixel data that will be uploaded. There are many
constants which are accepted but GL_RGB is the value that is widely
used. </li><li><em>type</em> - Type of data that will be uploaded. Again there are several symbolic constants but the one which I use is GL_UNSIGNED_BYTE.
            </li><li><em>pixels - </em>Pointer
to the image data. This is the image data that will be uploaded to the
video memory. Note that after your call to glTexImage2D you can free
this memory since the texture is already uploaded into video memory. </li></font></ul>
<font color="black">        </font><p><font color="black">Now that you know the parameters for <em>glTexImage2D</em> here is a sample call:</font></p>
<font color="black">        </font><blockquote><span class="code"><font color="black">glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);</font></span></blockquote>
<font color="black">        </font></td>
    </tr>
</tbody></table>
</center></div>

<p>Thats all folks! After you have done everything above the texture
will be uploaded and ready to be applied to your geometry. The next
section will discuss the application of the texutre to geometry. If
this does not seem clear to you look at the links section at the end of
this document for a texture mapping example.
</p><h1>Using the Texture</h1>
<p>Well now that you have your texture uploaded you want to do
something with it since its useless just sitting in memory. The process
for applying a texture to geometry greatly depends on what type of data
you are dealing with and how you would like things to run. Due to this
fact in this section I will relay you some pointers on texture mapping,
give an example of how to texture a quad and explain the texture
coordinate system.
</p><p></p><div align="center"><center>
<table border="0" cellpadding="4" cellspacing="2" width="100%">
    <tbody><tr>
        <td align="center" bgcolor="#808080" width="100%"><font color="white"><b>Pointers</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0" width="100%">
        <ol style="color: black;">
            <li>Make sure that you have enabled texturing. You do this with the <em>glEnable (GL_TEXTURE_2D)</em> call.
            </li><li>Make sure that you bind to a texture before you do any sort of <em>glBegin/glEnd</em>. You cannot bind to a texture in the middle of a begin/end pair.
            </li><li>Make
sure that you specify a texture coordinate before each vertex that
makes up a face. If you have 3 verticies the pattern for texture
mapping the triangle would go like this: <em>TexCoord; VertexCoord; TexCoord; VertexCoord; TexCoord; VertexCoord; </em>
            </li><li>Make sure that you store your texture id's in variables, it makes things easier.
            </li><li>Make use of <em>glGenTextures</em>. Its the easy way to get a free texture id.
        </li></ol>
        </td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080" width="100%"><font color="white"><b>A Textured Quad</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0" width="100%"><p><font color="black">Below
is an example of how you would texture a quad. This code assumes that
texturing has been enabled and that there has been a texture uploaded
with the id of 13.</font>
        </p><blockquote><span class="code">glBindTexture (GL_TEXTURE_2D, 13);<br>
        glBegin (GL_QUADS);<br>
        glTexCoord2f (0.0, 0.0);<br>
        glVertex3f (0.0, 0.0, 0.0);<br>
        glTexCoord2f (1.0, 0.0);<br>
        glVertex3f (10.0, 0.0, 0.0);<br>
        glTexCoord2f (1.0, 1.0);<br>
        glVertex3f (10.0, 10.0, 0.0);<br>
        glTexCoord2f (0.0, 1.0);<br>
        glVertex3f (0.0, 10.0, 0.0);<br>
        glEnd ();</span></blockquote>
        </td>
    </tr>
    <tr>
        <td align="center" bgcolor="#808080" width="100%"><font color="white"><b>The Texture Coordinate System</b></font></td>
    </tr>
    <tr>
        <td bgcolor="#c0c0c0" width="100%"><p align="center"><img src="article947_files/texcoord.jpg"></p>
        <p><font color="black">The image above shows the OpenGL texture coordinate system. In the code above the calls to <em>glTexCoord2f</em> are very important as to what the end result of the texture mapping will be. When you make a call to <em>glTexCoord2f (x,y)</em>
OpenGL places the texture coordinate at that place on the image. If you
are texturing a triangle there will be three texture coords on the
image. Once a <em>glEnd</em> is reached the triangle which is formed
by the texture coordinates is then mapped onto the triangle that is
made up from the verticies.</font></p>
        </td>
    </tr>
</tbody></table>
</center></div>

<h2>Sample code:</h2>
<ul>
    <li><a href="http://www.gamedev.net/reference/programming/features/ogltm/pseudotexture.c">pseudotexture.c</a> -- Pseudo code for texture uploading and application.
    </li><li><a href="http://www.gamedev.net/reference/programming/features/ogltm/texture.zip">texture.zip</a> -- Real code for texture mapping a quad.
</li></ul>

<h2>Links:</h2>
<ul>
    <li><a href="http://trant.sgi.com/opengl/docs/man_pages/hardcopy/GL/html/gl/teximage2d.html">Documentation for glTexImage2D</a>
    </li><li><a href="http://www.opengl.org/">OpenGL.org</a>
    </li><li><a href="http://heron.cc.ukans.edu/ebt-bin/nph-dweb/dynaweb/SGI_Developer/OpenGL_PG/@Generic__BookTocView/7109;cd=7;td=6">RedBook Online</a>
</li></ul>

<p><b>Nate Miller</b><br>
7/02/99<br>
<a href="mailto:vandals1@home.com">vandals1@home.com</a><br>
<a href="http://members.home.com/vandals1">http://members.home.com/vandals1</a></p>

<p align="center"><b><a href="http://www.gamedev.net/community/forums/topic.asp?key=featart&amp;uid=947&amp;forum_id=35&amp;Topic_Title=OpenGL+Texture+Mapping%3A+An+Introduction">Discuss this article in the forums</a></b></p>
<p>
<br><span class="maintext-2">Date this article was posted to GameDev.net: <b>2/29/2000</b>
<br>(Note that this date does not necessarily correspond to the date the article was written)</span>
</p><p><b>See Also:</b><br>

<a href="http://www.gamedev.net/reference/list.asp?categoryid=169">General  </a><br>

</p><p align="center">© 1999-2008 Gamedev.net. All rights reserved. <a href="http://www.gamedev.net/info/legal.htm#copyright"><u>Terms of Use</u></a> <a href="http://www.gamedev.net/info/legal.htm#privacy"><u>Privacy Policy</u></a>
<br><span class="maintext-1">Comments? Questions? Feedback? <a href="http://www.gamedev.net/info/faq.asp">Click here!</a></span></p>

</td></tr></tbody></table>


<!-- start Vibrant Media IntelliTXT Tooltip style sheet -->
<style type="text/css">
.iTt{
    FONT-FAMILY:       Verdana, Arial, Helvetica;
    FONT-SIZE:         11px;
    FONT-STYLE:        normal;
    FONT-WEIGHT:       normal;
    COLOR:             black;
    BACKGROUND-COLOR:  lightyellow;
    BORDER:            black 1px solid;
    PADDING:           2px;
}
.iTt a {
    COLOR:             0000CC;
}
.iTt a:visited {
    COLOR:             0000CC;
}
.iTt a:hover {
    COLOR:             6666CC;
}
.iTt TD {
   COLOR:              999999;
}
</style>
<!-- end Vibrant Media IntelliTXT style sheet -->
<!-- start Vibrant Media IntelliTXT script section -->
<script type="text/javascript" src="article947_files/front.asp"></script>
<!-- end Vibrant Media IntelliTXT script section -->

<script src="article947_files/urchin.js" type="text/javascript">
</script>
<script type="text/javascript">
_uacct = "UA-279474-1";
urchinTracker();
</script>
</body></html>