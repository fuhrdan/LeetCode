impl Solution{pub fn min_cost(c:Vec<Vec<i32>>)->i32{let(mut a,mut b,mut d)=(0,0,0);for x in c{let(na,nb,nd)=(x[0]+b.min(d),x[1]+a.min(d),x[2]+a.min(b));a=na;b=nb;d=nd;}a.min(b).min(d)}}
