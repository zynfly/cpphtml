//
// Created by Administrator on 2017/11/23.
//

#include "html_build.hpp"


html_build::html_build()
{
    ADD_NODE(a)
    ADD_NODE(abbr)
    ADD_NODE(acronym)
    ADD_NODE(address)
    ADD_NODE(applet)
    ADD_NODE(area)
    ADD_NODE(article)
    ADD_NODE(aside)
    ADD_NODE(audio)
    ADD_NODE(b)
    ADD_NODE(base)
    ADD_NODE(basefont)
    ADD_NODE(bdi)
    ADD_NODE(bdo)
    ADD_NODE(big)
    ADD_NODE(blockquote)
    ADD_NODE(body)
    ADD_NODE(br)
    ADD_NODE(button)
    ADD_NODE(canvas)
    ADD_NODE(caption)
    ADD_NODE(center)
    ADD_NODE(cite)
    ADD_NODE(code)
    ADD_NODE(col)
    ADD_NODE(colgroup)
    ADD_NODE(command)
    ADD_NODE(datalist)
    ADD_NODE(dd)
    ADD_NODE(del)
    ADD_NODE(details)
    ADD_NODE(dir)
    ADD_NODE(div)
    ADD_NODE(dfn)
    ADD_NODE(dialog)
    ADD_NODE(dl)
    ADD_NODE(dt)
    ADD_NODE(em)
    ADD_NODE(embed)
    ADD_NODE(fieldset)
    ADD_NODE(figcaption)
    ADD_NODE(figure)
    ADD_NODE(font)
    ADD_NODE(footer)
    ADD_NODE(form)
    ADD_NODE(frame)
    ADD_NODE(frameset)
    ADD_NODE(h1)
    ADD_NODE(h2)
    ADD_NODE(h3)
    ADD_NODE(h4)
    ADD_NODE(h5)
    ADD_NODE(h6)
    ADD_NODE(head)
    ADD_NODE(header)
    ADD_NODE(hr)
    ADD_NODE(html)
    ADD_NODE(i)
    ADD_NODE(iframe)
    ADD_NODE(img)
    ADD_NODE(input)
    ADD_NODE(ins)
    ADD_NODE(isindex)
    ADD_NODE(kbd)
    ADD_NODE(keygen)
    ADD_NODE(label)
    ADD_NODE(legend)
    ADD_NODE(li)
    ADD_NODE(link)
    ADD_NODE(map)
    ADD_NODE(mark)
    ADD_NODE(menu)
    ADD_NODE(menuitem)
    ADD_NODE(meta)
    ADD_NODE(meter)
    ADD_NODE(nav)
    ADD_NODE(noframes)
    ADD_NODE(noscript)
    ADD_NODE(object)
    ADD_NODE(ol)
    ADD_NODE(optgroup)
    ADD_NODE(option)
    ADD_NODE(output)
    ADD_NODE(p)
    ADD_NODE(param)
    ADD_NODE(pre)
    ADD_NODE(progress)
    ADD_NODE(q)
    ADD_NODE(rp)
    ADD_NODE(rt)
    ADD_NODE(ruby)
    ADD_NODE(s)
    ADD_NODE(samp)
    ADD_NODE(script)
    ADD_NODE(section)
    ADD_NODE(select)
    ADD_NODE(small)
    ADD_NODE(source)
    ADD_NODE(span)
    ADD_NODE(strike)
    ADD_NODE(strong)
    ADD_NODE(style)
    ADD_NODE(sub)
    ADD_NODE(summary)
    ADD_NODE(sup)
    ADD_NODE(table)
    ADD_NODE(tbody)
    ADD_NODE(td)
    ADD_NODE(textarea)
    ADD_NODE(tfoot)
    ADD_NODE(th)
    ADD_NODE(thead)
    ADD_NODE(time)
    ADD_NODE(title)
    ADD_NODE(tr)
    ADD_NODE(track)
    ADD_NODE(tt)
    ADD_NODE(u)
    ADD_NODE(ul)
    ADD_NODE(var)
    ADD_NODE(video)
    ADD_NODE(wbr)
    ADD_NODE(xmp)

    ADD_ATTR(accesskey)
    ADD_ATTR(class)
    ADD_ATTR(contenteditable)
    ADD_ATTR(contextmenu)
    ADD_ATTR(dir)
    ADD_ATTR(draggable)
    ADD_ATTR(dropzone)
    ADD_ATTR(hidden)
    ADD_ATTR(id)
    ADD_ATTR(lang)
    ADD_ATTR(spellcheck)
    ADD_ATTR(style)
    ADD_ATTR(tabindex)
    ADD_ATTR(title)
    ADD_ATTR(translate)
    ADD_ATTR(onafterprint)
    ADD_ATTR(onbeforeprint)
    ADD_ATTR(onbeforeunload)
    ADD_ATTR(onerror)
    ADD_ATTR(onhaschange)
    ADD_ATTR(onload)
    ADD_ATTR(onmessage)
    ADD_ATTR(onoffline)
    ADD_ATTR(ononline)
    ADD_ATTR(onpagehide)
    ADD_ATTR(onpageshow)
    ADD_ATTR(onpopstate)
    ADD_ATTR(onredo)
    ADD_ATTR(onresize)
    ADD_ATTR(onstorage)
    ADD_ATTR(onundo)
    ADD_ATTR(onunload)
    ADD_ATTR(onblur)
    ADD_ATTR(onchange)
    ADD_ATTR(oncontextmenu)
    ADD_ATTR(onfocus)
    ADD_ATTR(onformchange)
    ADD_ATTR(onforminput)
    ADD_ATTR(oninput)
    ADD_ATTR(oninvalid)
    ADD_ATTR(onreset)
    ADD_ATTR(onselect)
    ADD_ATTR(onsubmit)
    ADD_ATTR(onkeydown)
    ADD_ATTR(onkeypress)
    ADD_ATTR(onkeyup)
    ADD_ATTR(onclick)
    ADD_ATTR(ondblclick)
    ADD_ATTR(ondrag)
    ADD_ATTR(ondragend)
    ADD_ATTR(ondragenter)
    ADD_ATTR(ondragleave)
    ADD_ATTR(ondragover)
    ADD_ATTR(ondragstart)
    ADD_ATTR(ondrop)
    ADD_ATTR(onmousedown)
    ADD_ATTR(onmousemove)
    ADD_ATTR(onmouseout)
    ADD_ATTR(onmouseover)
    ADD_ATTR(onmouseup)
    ADD_ATTR(onmousewheel)
    ADD_ATTR(onscroll)
    ADD_ATTR(onabort)
    ADD_ATTR(oncanplay)
    ADD_ATTR(oncanplaythrough)
    ADD_ATTR(ondurationchange)
    ADD_ATTR(onemptied)
    ADD_ATTR(onended)
    ADD_ATTR(onerror)
    ADD_ATTR(onloadeddata)
    ADD_ATTR(onloadedmetadata)
    ADD_ATTR(onloadstart)
    ADD_ATTR(onpause)
    ADD_ATTR(onplay)
    ADD_ATTR(onplaying)
    ADD_ATTR(onprogress)
    ADD_ATTR(onratechange)
    ADD_ATTR(onreadystatechange)
    ADD_ATTR(onseeked)
    ADD_ATTR(onseeking)
    ADD_ATTR(onstalled)
    ADD_ATTR(onsuspend)
    ADD_ATTR(ontimeupdate)
    ADD_ATTR(onvolumechange)
    ADD_ATTR(onwaiting)
    ADD_ATTR(charset)
    ADD_ATTR(coords)
    ADD_ATTR(download)
    ADD_ATTR(href)
    ADD_ATTR(hreflang)
    ADD_ATTR(media)
    ADD_ATTR(name)
    ADD_ATTR(rel)
    ADD_ATTR(rev)
    ADD_ATTR(shape)
    ADD_ATTR(target)
    ADD_ATTR(type)
    ADD_ATTR(code)
    ADD_ATTR(object)
    ADD_ATTR(align)
    ADD_ATTR(alt)
    ADD_ATTR(archive)
    ADD_ATTR(codebase)
    ADD_ATTR(height)
    ADD_ATTR(hspace)
    ADD_ATTR(name)
    ADD_ATTR(vspace)
    ADD_ATTR(width)
    ADD_ATTR(alt)
    ADD_ATTR(coords)
    ADD_ATTR(href)
    ADD_ATTR(nohref)
    ADD_ATTR(shape)
    ADD_ATTR(target)
    ADD_ATTR(autoplay)
    ADD_ATTR(controls)
    ADD_ATTR(loop)
    ADD_ATTR(muted)
    ADD_ATTR(preload)
    ADD_ATTR(src)
    ADD_ATTR(href)
    ADD_ATTR(target)
    ADD_ATTR(color)
    ADD_ATTR(face)
    ADD_ATTR(size)
    ADD_ATTR(dir)
    ADD_ATTR(dir)
    ADD_ATTR(cite)
    ADD_ATTR(alink)
    ADD_ATTR(background)
    ADD_ATTR(bgcolor)
    ADD_ATTR(link)
    ADD_ATTR(text)
    ADD_ATTR(vlink)
    ADD_ATTR(autofocus)
    ADD_ATTR(disabled)
    ADD_ATTR(form)
    ADD_ATTR(formaction)
    ADD_ATTR(formenctype)
    ADD_ATTR(formmethod)
    ADD_ATTR(formnovalidate)
    ADD_ATTR(formtarget)
    ADD_ATTR(name)
    ADD_ATTR(type)
    ADD_ATTR(value)
    ADD_ATTR(height)
    ADD_ATTR(width)
    ADD_ATTR(align)
    ADD_ATTR(char)
    ADD_ATTR(charoff)
    ADD_ATTR(span)
    ADD_ATTR(valign)
    ADD_ATTR(checked)
    ADD_ATTR(disabled)
    ADD_ATTR(icon)
    ADD_ATTR(label)
    ADD_ATTR(radiogroup)
    ADD_ATTR(type)
    ADD_ATTR(cite)
    ADD_ATTR(datetime)
    ADD_ATTR(open)
    ADD_ATTR(compact)
    ADD_ATTR(src)
    ADD_ATTR(disabled)
    ADD_ATTR(form)
    ADD_ATTR(accept)
    ADD_ATTR(accept-charset)
    ADD_ATTR(action)
    ADD_ATTR(autocomplete)
    ADD_ATTR(enctype)
    ADD_ATTR(method)
    ADD_ATTR(novalidate)
    ADD_ATTR(target)
    ADD_ATTR(scrolling)
    ADD_ATTR(frameborder)
    ADD_ATTR(longdesc)
    ADD_ATTR(marginheight)
    ADD_ATTR(marginwidth)
    ADD_ATTR(noresize)
    ADD_ATTR(cols)
    ADD_ATTR(rows)
    ADD_ATTR(profile)
    ADD_ATTR(noshade)
    ADD_ATTR(manifest)
    ADD_ATTR(xmlns)
    ADD_ATTR(frameborder)
    ADD_ATTR(longdesc)
    ADD_ATTR(sandbox)
    ADD_ATTR(scrolling)
    ADD_ATTR(seamless)
    ADD_ATTR(srcdoc)
    ADD_ATTR(alt)
    ADD_ATTR(border)
    ADD_ATTR(hspace)
    ADD_ATTR(ismap)
    ADD_ATTR(longdesc)
    ADD_ATTR(usemap)
    ADD_ATTR(vspace)
    ADD_ATTR(accept)
    ADD_ATTR(autocomplete)
    ADD_ATTR(autofocus)
    ADD_ATTR(formaction)
    ADD_ATTR(formenctype)
    ADD_ATTR(formmethod)
    ADD_ATTR(formnovalidate)
    ADD_ATTR(formtarget)
    ADD_ATTR(list)
    ADD_ATTR(max)
    ADD_ATTR(maxlength)
    ADD_ATTR(min)
    ADD_ATTR(multiple)
    ADD_ATTR(pattern)
    ADD_ATTR(placeholder)
    ADD_ATTR(readonly)
    ADD_ATTR(required)
    ADD_ATTR(step)
    ADD_ATTR(datetime)
    ADD_ATTR(cite)
    ADD_ATTR(autofocus)
    ADD_ATTR(challenge)
    ADD_ATTR(keytype)
    ADD_ATTR(for)
    ADD_ATTR(form)
    ADD_ATTR(charset)
    ADD_ATTR(href)
    ADD_ATTR(hreflang)
    ADD_ATTR(rel)
    ADD_ATTR(rev)
    ADD_ATTR(target)
    ADD_ATTR(id)
    ADD_ATTR(label)
    ADD_ATTR(checked)
    ADD_ATTR(default)
    ADD_ATTR(disabled)
    ADD_ATTR(radiogroup)
    ADD_ATTR(content)
    ADD_ATTR(http-equiv)
    ADD_ATTR(scheme)
    ADD_ATTR(form)
    ADD_ATTR(high)
    ADD_ATTR(low)
    ADD_ATTR(optimum)
    ADD_ATTR(value)
    ADD_ATTR(archive)
    ADD_ATTR(border)
    ADD_ATTR(classid)
    ADD_ATTR(codebase)
    ADD_ATTR(codetype)
    ADD_ATTR(data)
    ADD_ATTR(declare)
    ADD_ATTR(hspace)
    ADD_ATTR(standby)
    ADD_ATTR(usemap)
    ADD_ATTR(vspace)
    ADD_ATTR(width)
    ADD_ATTR(compact)
    ADD_ATTR(reversed)
    ADD_ATTR(start)
    ADD_ATTR(type)
    ADD_ATTR(disabled)
    ADD_ATTR(selected)
    ADD_ATTR(valuetype)
    ADD_ATTR(async)
    ADD_ATTR(charset)
    ADD_ATTR(defer)
    ADD_ATTR(language)
    ADD_ATTR(autofocus)
    ADD_ATTR(multiple)
    ADD_ATTR(required)
    ADD_ATTR(bgcolor)
    ADD_ATTR(border)
    ADD_ATTR(cellpadding)
    ADD_ATTR(cellspacing)
    ADD_ATTR(frame)
    ADD_ATTR(rules)
    ADD_ATTR(summary)
    ADD_ATTR(valign)
    ADD_ATTR(abbr)
    ADD_ATTR(axis)
    ADD_ATTR(colspan)
    ADD_ATTR(headers)
    ADD_ATTR(nowrap)
    ADD_ATTR(rowspan)
    ADD_ATTR(scope)
    ADD_ATTR(valign)
    ADD_ATTR(autofocus)
    ADD_ATTR(cols)
    ADD_ATTR(maxlength)
    ADD_ATTR(placeholder)
    ADD_ATTR(readonly)
    ADD_ATTR(required)
    ADD_ATTR(rows)
    ADD_ATTR(wrap)
    ADD_ATTR(headers)
    ADD_ATTR(nowrap)
    ADD_ATTR(rowspan)
    ADD_ATTR(scope)
    ADD_ATTR(datetime)
    ADD_ATTR(pubdate)
    ADD_ATTR(dir)
    ADD_ATTR(lang)
    ADD_ATTR(default)
    ADD_ATTR(kind)
    ADD_ATTR(srclang)
    ADD_ATTR(compact)
    ADD_ATTR(autoplay)
    ADD_ATTR(controls)
    ADD_ATTR(loop)
    ADD_ATTR(muted)
    ADD_ATTR(poster)
    ADD_ATTR(preload)
}