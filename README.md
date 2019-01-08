# ByteDance
2019年1月字节跳动广告系统后端开发工程师面试问题回忆

* 形式：现场面试 单面
* 时间：2019年1月8日下午2点半
* 地点：北京市海淀区丹棱街1号互联网金融中心17层

面试官是一位很年轻的男的，做前端的，问的大部分都是Node.js相关的问题

## 1.回调函数、promise、generator/yield、async/await有哪些异同？
回调函数是js中的概念，一类特殊的函数，可以作为参数传给主函数，在主函数执行完之后调用该函数。前端的ajax请求就用到了回调函数。

```
//定义主函数，回调函数作为参数
function A(callback) {
    callback();  
    console.log('我是主函数');      
}

//定义回调函数
function B(){
    setTimeout("console.log('我是回调函数')", 3000);//模仿耗时操作  
}

//调用主函数，将函数B传进去
A(B);

//输出结果
我是主函数
我是回调函数
```
Promise 是异步编程的一种解决方案，比传统的解决方案——回调函数和事件——更合理和更强大。它由社区最早提出和实现，ES6 将其写进了语言标准，统一了用法，原生提供了Promise对象。有了 Promise 对象，就可以将异步操作以同步操作的流程表达出来，避免了层层嵌套的回调函数。此外，Promise 对象提供的接口，使得控制异步操作更加容易。
```
var promise = new Promise(function(resolve, reject) {
  if (/* 异步操作成功 */){
    resolve(value);
  } else {
    reject(error);
  }
});
 
promise.then(function(value) {
  // success
}, function(value) {
  // failure
});
```
Generator 函数是 ES6 提供的一种异步编程解决方案。一个Generator函数与普通function的区别就是函数名前面多了一个星号 * 但是执行时有很大不同，与yield命令配合，可以实现暂停执行的功能，意味着可以把异步操作写在yield表达式里面，等到调用next方法时再往后执行。这实际上等同于不需要写回调函数了。
```
function* loadUI() {
  showLoadingScreen();
  yield loadUIDataAsynchronously();
  hideLoadingScreen();
}
var loader = loadUI();
// 加载UI
loader.next()

// 卸载UI
loader.next()
```
ES2017 标准引入了 async 函数，使得异步操作变得更加方便。async 函数是什么？一句话，它就是 Generator 函数的语法糖,同时进行了一定的改进。
```
async function getStockPriceByName(name) {
  const symbol = await getStockSymbol(name);
  const stockPrice = await getStockPrice(symbol);
  return stockPrice;
}
```
总的来说async/await的实现最简洁，最符合语义，几乎没有语义不相关的代码。

## 2.Node.js单线程、非阻塞具体是怎么实现的？
事件驱动。有点像单个窗口，客户排队点餐，点完餐直接去座位上等着就行，而下一个客户可以接着点餐，而不用等前一个客户取完餐再点。而多线程相当于是开了多个窗口。I/O阻塞相当于是下一个客户必须等前一个客户取完餐之后才可以开始点餐。

## 3.你知道的HTTP状态码有哪些？分别表示什么含义？
常见的HTTP状态码：
* 200 请求成功
* 401 要求用户的身份认证
* 404 请求的资源不存在
* 500 内部服务器错误
* 301 资源被永久转移到其它URL
* 100 继续,客户端应继续其请求

分类：
* 1xx 信息
* 2xx 成功
* 3xx 重定向
* 4xx 客户端错误
* 5xx 服务器错误

## 4.你对浏览器缓存了解多少？
简单来说，浏览器缓存就是把一个已经请求过的Web资源（如html页面，图片，js，数据等）拷贝一份副本储存在浏览器中。缓存会根据进来的请求保存输出内容的副本。当下一个请求来到的时候，如果是相同的URL，缓存会根据缓存机制决定是直接使用副本响应访问请求，还是向源服务器再次发送请求。

## 5.tcp协议是如何建立和释放连接的？
三次握手建立连接。
第一次握手：A给B打电话说，你可以听到我说话吗？（seq=x）
第二次握手：B收到了A的信息，然后对A说： 我可以听得到你说话啊，你能听得到我说话吗？（ACK=x+1，seq=y）  
第三次握手：A收到了B的信息，然后说可以的，我要给你发信息啦！（ack=y+1）

四次挥手释放连接。
A:喂，我不说了。(FIN)
B:我知道了。等下，上一句还没说完。Balabala…..（ACK）
B:好了，说完了，我也不说了。（FIN）
A:我知道了。(ACK)
A等待2MSL,保证B收到了消息,否则重说一次我知道了。

## 6.OSI模型和TCP/IP模型分别有哪几层，HTTP协议属于哪一层？
OSI模型分为7层：
* 物理层
* 数据链路层
* 网络层
* 传输层
* 会话层
* 表示层
* 应用层

实际应用中基本都是5层，没有表示层和会话层的，应该说它们和应用层合并了。我们需要关注的主要是应用层（HTTP协议）和传输层（TCP协议）。

TCP/IP把分为4层：
* 网络接口层
* 网络层 IP
* 运输层 TCP UDP
* 应用层 HTTP、FTP

## 7.什么是RPC？它在7层模型中属于哪一层？与HTTP有什么区别？
是一种通过网络从远程计算机程序上请求服务，而不需要了解底层网络技术的协议。在OSI网络通信模型中，RPC跨越了传输层和应用层。RPC使得开发包括网络分布式多程序在内的应用程序更加容易。

## 8.进程间通讯的方式有哪些？
* 管道（PIPE）
* 消息排队
* 旗语
* 共用内存
* 套接字（Socket）

## 9.子网掩码是如何工作的？
每一个IP地址分为网络标识和主机标识。IP地址与子网掩码做与运算得到网络标识。

## 10.koa怎么获取POST请求中的参数？写出具体代码。如果用Node.js原生方法怎么实现？服务端怎么区分body的不同格式？
Node.js原生方法：
```
var http = require('http');
var querystring = require('querystring');
 
http.createServer(function(req, res){
    // 定义了一个post变量，用于暂存请求体的信息
    var post = '';     
 
    // 通过req的data事件监听函数，每当接受到请求体的数据，就累加到post变量中
    req.on('data', function(chunk){    
        post += chunk;
    });
 
    // 在end事件触发后，通过querystring.parse将post解析为真正的POST请求格式，然后向客户端返回。
    req.on('end', function(){    
        post = querystring.parse(post);
        res.end(util.inspect(post));
    });
}).listen(3000);
```

koa方法：
```
const Koa = require('koa')
const app = new Koa()

// get请求
app.use( async (ctx) => {
    ctx.body = {
        url: ctx.url,
        ctx_query: ctx.query,
        ctx_querystring: ctx.querystring
    }
})

// post请求
const bodyParser = require('koa-bodyparser')
app.use(bodyParser())
app.use( async (ctx) => {
    ctx.body =  ctx.request.body
})
```
服务端通常是根据请求头（headers）中的 Content-Type 字段来获知请求中的消息主体是用何种方式编码（application/x-www-form-urlencoded,multipart/form-data,application/json,text/xml），再对body进行解析。
